/*
 * ex_03.cpp
 *
 * Se tiene un listado de deudas no ordenado en el archivo binario G06E03.bin.
 * Cada deuda tiene un cliente guardado con 8 caracteres, el número del mes en
 * el que tomó la deuda y la cantidad adeudada (como número entero). Se pide
 * primero leer el archivo y armar un lista ordenada por cliente y a igualdad
 * de cliente por mes, luego mostrar esa lista inicial por pantalla.
 * Luego se quiere hacer la consolidación de la deuda, esto es, para cada
 * cliente, si tiene varios registros con el mismo mes, dejar uno solo con el
 * total de la deuda en dicho mes. Para ello debe programar dos funciones
 * auxiliares. La función “borrar siguiente” recibe como parámetro un puntero
 * a un nodo de la lista y borra el nodo siguiente. La función “consolidar”
 * recibe la lista y la modifica para dejar la versión consolidada, usando la
 * función “borrar siguiente” como ayuda. Al finalizar se mostrará por pantalla
 * la lista consolidada.
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

#define DATA_FILE "data/G06E03.bin"

#define CLIENT_SIZE 8

typedef struct data {
    string client = "";
    int month = 0;
    int debt = 0;
} data_t;

ostream& operator << (ostream &os, const data_t& data)
{
	os << data.client << "\t" << data.month << "\t" << data.debt;
	return os;
}

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

fstream& operator >> (fstream &fs, const data_t& data)
{
	writestring(fs, data.client, CLIENT_SIZE);
	fs.write(reinterpret_cast<const char *>(&data.month), sizeof(data.month));
	fs.write(reinterpret_cast<const char *>(&data.debt), sizeof(data.debt));
	return fs;
}

fstream& operator >> (fstream &fs, data_t& data)
{
	data.client = readstring(fs, CLIENT_SIZE);
	fs.read(reinterpret_cast<char *>(&data.month), sizeof(data.month));
	fs.read(reinterpret_cast<char *>(&data.debt), sizeof(data.debt));
	return fs;
}

bool criteriaClients(data_t a, data_t b)
{
    if (a.client >= b.client) {
        if (a.client == b.client) {
            return (a.month >= b.month);
        }
        return true;
    }
    return false;
}

int readbin(string filename, Node<data_t>* &ol)
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    data_t data;
    while(file >> data) {
        insert(data, ol, criteriaClients);
    }

    file.close();
    return 0;
}

template <typename T> void
removeNext (Node<T>* &stack) {
    if(stack->next != nullptr) {
        Node<T>* foo = stack->next;
        stack->next = stack->next->next;
        delete foo;
    }
}

void consolidateDebt(Node<data_t>* &ol) {
    Node<data_t> *ps = ol;
    while(!stackEmpty(ps) && !stackEmpty(ps->next)) {
        if(criteriaClients(ps->data, ps->next->data)) {
            ps->data.debt += ps->next->data.debt;
            removeNext(ps);
        } else {
            ps = ps->next;
        }
    }
}

int main(int argc, char *argv[])
{
    Node<data_t>* ol = nullptr;

    readbin(DATA_FILE, ol);
    stackPrint(ol);

    cout << endl;

    consolidateDebt(ol);
    stackPrint(ol);

    stackErase(ol);

    return 0;
}
