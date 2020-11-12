 /*
 * ex_01.cpp
 *
 * Se dispone del archivo binario G07E01.bin que contiene una lista no ordenada
 * de ventas. Cada venta tiene una campo modelo que es un string guardado en el
 * archivo con 10 caracteres y el campo cantidad vendida que es un entero.
 *
 * Se pide: Leer el archivo y cargar la estructura de datos necesaria para
 * emitir el listado de cada modelo con la cantidad total vendida, ordenado
 * ascendentemente por modelo.
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
#include "linkedLists/linkedLists.h"

using namespace std;

#define DATA_FILE "data/G07E01.bin"

#define MODEL_SIZE 10

typedef struct product {
    string model = "";
    int qty = 0;
} product_t;

void writestring(fstream &fs, string str, unsigned int size)
{
	str.resize(size);
	fs.write(str.data(), size);
}

string readstring(fstream &fs, unsigned int size)
{
	char *buffer = new char[size + 1];
	buffer[size] = '\0';
	fs.read(buffer, size);
	string str(buffer);
	delete[] buffer;
	return str;
}


fstream& operator >> (fstream &fs, const product_t& prod)
{
	writestring(fs, prod.model, MODEL_SIZE);
	fs.write(reinterpret_cast<const char *>(&prod.qty), sizeof(prod.qty));
	return fs;
}

fstream& operator >> (fstream &fs, product_t& prod)
{
	prod.model = readstring(fs, MODEL_SIZE);
	fs.read(reinterpret_cast<char *>(&prod.qty), sizeof(prod.qty));
	return fs;
}

ostream& operator << (ostream &os, const product_t& prod)
{
	os << prod.model << "\t" << prod.qty;
	return os;
}

int criteriaModels(product_t a, product_t b)
{
	if (a.model == b.model) {
		return 0;
    }

    return a.model > b.model ? 1 : -1;
}

int readbin(string filename, Node<product_t>* &ol, int (*criteria)(product_t, product_t))
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    product_t data;
    product_t aux;
    aux.qty = 0;
    while(file >> data) {
        aux.model = data.model;
        Node<product_t>* p = insert_unique(aux, ol, criteria);
        p->data.qty += data.qty;
    }

    file.close();
    return 0;
}

int main(int argc, char *argv[])
{
    Node<product_t>* ol = nullptr;

    readbin(DATA_FILE, ol, criteriaModels);
    stackPrint(ol);

    stackErase(ol);

    return 0;
}
