/* segunda-entrega.cpp
 *
 * Véase el archivo ASSIGNMENT para leer la consigna del programa.
 *
 * Copyright (c) 2020 Savinelli Roberto Nicolás <rsavinelli@est.frba.utn.edu.ar>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <iostream>
#include <cassert>
#include <fstream>

#define PRODUCTS_FILE "products.txt"
#define COLOURS_FILE "colours.txt"
#define PRODUCTION_FILE "production.txt"

#define N_PRODUCTS 6
#define N_COLOURS 3
#define COLS N_COLOURS

#define ERROR -1
//#define NDEBUG 1

using namespace std;

struct answer {
    float value;
    string description;
};

struct matrixdata {
    int value;
    unsigned int x;
    unsigned int y;
};

struct vectordata {
    int value;
    unsigned int index;
};

int
readfile(string file_name, string buff[], unsigned const int size)
{
    assert(buff);

    ifstream file;

    file.open(file_name);

    if (!file.is_open()) {
        return ERROR;
    }

    for (unsigned int i = 0; i < size; i++) {
        file >> buff[i];
    }

    file.close();
    return 0;
}

void
matrix2Dclear(int matrix[][COLS], unsigned const int rows)
{
    assert(matrix);

    for (unsigned int i = 0; i < rows; i++)
        for (unsigned int j = 0; j < COLS; j++)
            matrix[i][j] = 0;
}


int
getcatalogue(string products[], unsigned const int n_products,
        string colours[], unsigned const int n_colours,
        string catalogue[][N_COLOURS])
{
    assert(catalogue);
    assert(products);
    assert(colours);

    /* COLUMN SIZE CANNOT BE MODIFIED */
    if(n_colours != N_COLOURS) {
        return ERROR;
    }

    for (unsigned int i = 0; i < n_products; i++) {
        for (unsigned int j = 0; j < n_colours; j++) {
            catalogue[i][j] = products[i];
            (catalogue[i][j] += " ") += colours[j];
        }
    }

    return 0;
}

int
getproduction(string file_name, int production[][N_COLOURS],
        int production_batch[][N_COLOURS], unsigned const int n_products,
        unsigned const int n_colours)
{
    assert(production);
    assert(production_batch);

    /* COLUMN SIZE CANNOT BE MODIFIED */
    if(n_colours != N_COLOURS) {
        return ERROR;
    }

    ifstream file;

    file.open(file_name);

    if (!file.is_open()) {
        return ERROR;
    }

    matrix2Dclear(production, n_products);
    matrix2Dclear(production_batch, n_products);

    struct matrixdata data;

    file >> data.x;
    while (!file.eof()) {
        if (!(file >> data.y))
            break;

        if (!(file >> data.value))
            break;

        production[data.x][data.y] += data.value;
        production_batch[data.x][data.y]++;

        file >> data.x;
    }

    file.close();
    return 0;
}

struct answer
min_production(int production[][N_COLOURS], string products[],
        unsigned const int n_products, unsigned const int n_colours)
{
    assert(production);
    assert(products);

    int sum[n_products] {0};

    for (unsigned int i = 0; i < n_products; i++)
        for (unsigned int j = 0; j < n_colours; j++)
            sum[i] += production[i][j];

    struct vectordata min;
    min.value = sum[0];
    min.index = 0;

    for (unsigned int i = 0; i < n_products; i++) {
        if (sum[i] < min.value) {
            min.value = sum[i];
            min.index = i;
        }
    }

    struct answer ans;
    ans.value = min.value;
    ans.description = products[min.index];

    return ans;
}

struct answer
max_productionmean(int production[][N_COLOURS], int production_batch[][N_COLOURS],
        string catalogue[][N_COLOURS], unsigned const int products,
        unsigned const int colours)
{
    assert(catalogue);
    assert(production);
    assert(production_batch);

    struct matrixdata maxmean;
    maxmean.value = production[0][0] / production_batch[0][0];
    maxmean.x = 0;
    maxmean.y = 0;

    float mean;
    for(unsigned int i = 0; i < products; i++) {
        for(unsigned int j = 1; j < colours; j++) {
            mean = production[i][j] / production_batch[i][j];
            if (maxmean.value < mean) {
                maxmean.value = mean;
                maxmean.x = i;
                maxmean.y = j;
            }
        }
    }

    struct answer ans;
    ans.value = maxmean.value;
    ans.description = catalogue[maxmean.x][maxmean.y];

    return ans;
}

struct answer
max_production(int production[][N_COLOURS], string catalogue[][N_COLOURS],
        unsigned const int products, unsigned const int colours)
{
    assert(catalogue);
    assert(production);

    struct matrixdata maxp;
    maxp.value = production[0][0];
    maxp.x = 0;
    maxp.y = 0;

    int prod;
    for (unsigned int i = 0; i < products; i++) {
        for (unsigned int j = 0; j < colours; j++) {
            prod = production[i][j];
            if (maxp.value < prod) {
                maxp.value = prod;
                maxp.x = i;
                maxp.y = j;
            }
        }
    }

    struct answer ans;
    ans.value = maxp.value;
    ans.description = catalogue[maxp.x][maxp.y];

    return ans;
}


int main(void)
{
    /* CATALOGUE */
    string products[N_PRODUCTS];
    string colours[N_COLOURS];

    if (readfile(PRODUCTS_FILE, products, N_PRODUCTS)) {
        cout << "failed to read " << PRODUCTS_FILE << "." << endl;
        return ERROR;
    }

    if (readfile(COLOURS_FILE, colours, N_COLOURS)) {
        cout << "failed to read " << COLOURS_FILE << "." << endl;
        return ERROR;
    }

    string catalogue[N_PRODUCTS][N_COLOURS];

    if (getcatalogue(products, N_PRODUCTS, colours, N_COLOURS, catalogue)) {
        cout << "failed to create catalogue." << endl;
        return ERROR;
    }

    /* PRODUCTION DATA */
    int production[N_PRODUCTS][N_COLOURS];
    int production_batch[N_PRODUCTS][N_COLOURS];

    if (getproduction(PRODUCTION_FILE, production, production_batch, N_PRODUCTS, N_COLOURS)) {
        cout << "failed to read " << PRODUCTION_FILE << "." << endl;
        return ERROR;
    }

    /* DATA ANALYSIS */
    struct answer ans;

    ans = max_production(production, catalogue, N_PRODUCTS, N_COLOURS);
    cout << ":: Producto-color con la mayor cantidad de de unidades producidas: " << endl
         << "   " << ans.description << " con " << ans.value
         << " unidades producidas." << endl << endl;

    ans = min_production(production, products, N_PRODUCTS, N_COLOURS);
    cout << ":: Producto con la menor cantidad de de unidades producidas: " << endl
         << "   " << ans.description << " con " << ans.value
         << " unidades promedio por lote." << endl << endl;

    ans = max_productionmean(production, production_batch, catalogue, N_PRODUCTS, N_COLOURS);
    cout << ":: Producto-color con el mayor promedio de unidades por lote: " << endl
         << "   " << ans.description << " con " << ans.value
         << " unidades promedio por lote." << endl;

    return 0;
}
