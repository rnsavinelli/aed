 /*
 * ex_02.cpp
 *
 * Copyright 2020 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

#include <iostream>
#include <fstream>
#include "linkedlists/linkedLists.h"
#include "rwstring/rwstring.h"

using namespace std;

#define DATA_FILE "data/G07E02.bin"

#define MODEL_SIZE 10
#define CITY_SIZE 12

typedef struct product {
    string model = "";
    int qty = 0;
} product_t;

typedef struct sales {
    string city = "";
    int n_products = 0;
    int total_sales = 0;
    Node<product_t>* product = nullptr;
} sales_t;

fstream& operator >> (fstream &fs, product_t& prod)
{
	prod.model = readstring(fs, MODEL_SIZE);
	fs.read(reinterpret_cast<char *>(&prod.qty), sizeof(prod.qty));
	return fs;
}

fstream& operator >> (fstream &fs, sales_t& sales)
{
    sales.city = readstring(fs, CITY_SIZE);
	return fs;
}

ostream& operator << (ostream &os, const product_t& prod)
{
	os << "\t" << prod.model << ", " << prod.qty << ".";
	return os;
}

ostream& operator << (ostream &os, const sales_t& sales)
{
	os << sales.city << ", " << sales.n_products << ", "<< sales.total_sales << ":" << endl;
    stackPrint(sales.product);
	return os;
}

int criteriaModels(product_t a, product_t b)
{
	if (a.model == b.model) {
		return 0;
    }

    return a.model > b.model ? 1 : -1;
}

int criteriaCity(sales_t a, sales_t b)
{
    return a.city.compare(b.city);
}

int solve1(string filename, Node<sales_t>* &sp)
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    sales_t sales = {"", 0, 0, nullptr};
    product_t product = {"", 0};
    while(file >> sales >> product) {
        Node<sales_t>* plocation = insert_unique(sales, sp, criteriaCity);
        append(plocation->data.product, product);
        plocation->data.total_sales += product.qty;
        plocation->data.n_products++;
    }

    Node<sales_t>* aux = sp;
    while(!stackEmpty(aux)) {
        cout << aux->data.city << ", " << aux->data.n_products << ", "
             << aux->data.total_sales << endl;
        aux = aux->next;
    }

    file.close();
    return 0;
}

void solve2(Node<sales_t>* p) {
    sales_t aux;

    cout << endl << "City: ";
    while(cin >> aux.city) {

        Node<sales_t> *hit = search(aux, p, criteriaCity);
        if(hit) {
            stackPrint(hit->data.product);
        } else {
			cout << "WARNING: " << aux.city << " Not Found."  << endl;
		}
        cout << endl << "City: ";
    }
}

void destroy(Node<sales_t>* &p) {
    while(!stackEmpty(p)) {
        while(!stackEmpty(p->data.product)) {
            pop(p->data.product);
        }
        pop(p);
    }
}

int main(int argc, char *argv[])
{
    Node<sales_t>* sp = nullptr;

    solve1(DATA_FILE, sp);
    solve2(sp);
    destroy(sp);

    return 0;
}
