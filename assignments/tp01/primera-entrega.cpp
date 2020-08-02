/* primera-entrega.cpp
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
#include <fstream>

/* ARCHIVOS PARA LEER DATOS */
#define PRODUCTS_FILE "products.txt"
#define COLOURS_FILE "colours.txt"
#define PRODUCTION_FILE "production.txt"

/* MACROS DEFINIDAS SEGÚN CONSIGNA */
#define N_PRODUCTS 6
#define N_COLOURS 3

#define ERROR -1
//#define NDEBUG 1

using namespace std;

/* ESTRUCTURAS CON UTILIDAD GENERICA */
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

int main(void)
{
    /* CATALOGO ***************************************************************
     * ************************************************************************/

    string products[N_PRODUCTS]
    string colours[N_COLOURS];

    /* products[N_PRODUCTS] almacena en un vector de strings los productos
     * del archivo "products.txt" en el orden en que son leídos.
     *
     * colours[N_COLOURS] almacena en un vector de strings los colores del
     * archivo "colours.txt" en el orden en que son leídos. */

    string catalogue[N_PRODUCTS][N_COLOURS];

    /* catalogue[N_PRODUCTS][N_COLOURS] almacena todas las combinaciones de
     * producto-color posibles en una matriz de strings.
     * Esto es, suponiendo la posición (i, j) tenemos:
     * products_and_colours[i][j] == "producto_i color_j"
     * ************************************************************************/

    /* DATOS DE PRODUCCIÓN ****************************************************
     * ************************************************************************/

    int production[N_PRODUCTS][N_COLOURS];

    /* production[N_PRODUCTS][N_COLOURS] almacena en una matriz de ints las
     * cantidades producidas de cada producto en cada color. Este enfoque nos
     * permite,independientemente del orden en que los colores aparezcan en el
     * archivo, poder interpretar la producción.*/

    int production_batch[N_PRODUCTS][N_COLOURS];

    /* production_batch[N_PRODUCTS][N_COLOURS] almacena en una matriz de ints la
     * cantidad de lotes de producción para cada combinación producto-color.
     * Es decir, por cada ocurrencia de "cantidad producida" de un combinación,
     * se incrementa en uno la misma significando los lotes.
     * ************************************************************************/

    return 0;
}
