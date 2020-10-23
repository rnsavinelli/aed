/*
 * ex_02.cpp
 *
 *  Se dispone del archivo binario G06E02.bin que contiene una lista no
 *  ordenada de órdenes de compras. Las mismas tienen los siguientes campos:
 *  id es un entero con un número que no se repite en ninguna otra orden.
 *  Cliente es un string que se guarda en el archivo binario con un largo de 8
 *  caracteres. Producto también es string y se guarda con largo 10. Cantidad
 *  es un entero con la cantidad pedida de ese producto por el cliente.
 *
 *  A. Se debe leer el archivo y cargar dos listas, la primera ordenada por
 *  cliente y a igualdad de cliente por producto (siempre ascendente). La otra
 *  por id (también ascendente). Luego de cargar las listas se mostrarán ambas
 *  por pantalla.
 *
 *  B. La lista ordenada por id está pensada para consultas, por eso luego de
 *  cargar las listas el programa pedirá un id, lo buscará y mostrará todos
 *  los datos de la orden de compra correspondiente o bien informará que no
 *  hay ninguna con ese número. El ciclo se corta cuando se ingresa un id
 *  negativo, ya que todos los id correctos son positivos.
 *
 *  C. Luego se pasa al despacho, para eso se pide al operador un nombre de
 *  cliente y un producto, de haber, se eliminan todos los registros
 *  correspondientes de AMBAS listas. A medida que se borran los registros se
 *  van mostrando por pantalla los eliminados, y una vez que se eliminaron todos
 *  los que corresponde, se muestran como quedaron ambas listas. Esto se hace en
 *  un ciclo hasta que se ingresa EOF.
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

#define DATA_FILE "data/G06E02.bin"

#define CLIENT_SIZE 8
#define PRODUCT_SIZE 10

typedef struct data {
    int id = 0;
    string client = "";
    string product = "";
    int qty = 0;
} data_t;

ostream& operator << (ostream &os, const data_t& data)
{
	os << data.id << "\t" << data.client << "\t" << data.product << "\t" << data.qty;
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

fstream& operator << (fstream &fs, const data_t& data)
{
	fs.write(reinterpret_cast<const char *>(&data.id), sizeof(data.id));
	writestring(fs, data.client, CLIENT_SIZE);
	writestring(fs, data.product, PRODUCT_SIZE);
	fs.write(reinterpret_cast<const char *>(&data.qty), sizeof(data.qty));
	return fs;
}

fstream& operator >> (fstream &fs, data_t& data)
{
	fs.read(reinterpret_cast<char *>(&data.id), sizeof(data.id));
	data.client = readstring(fs, CLIENT_SIZE);
	data.product = readstring(fs, PRODUCT_SIZE);
	fs.read(reinterpret_cast<char *>(&data.qty), sizeof(data.qty));
	return fs;
}

bool criteriaClients(data_t a, data_t b)
{
    if (a.client > b.client) {
        return true;
    } else if (a.client == b.client) {
        if (a.product >= b.product) {
            return true;
        }
    }

    return false;
}

bool criteriaIDAsc(data_t a, data_t b)
{
    if (a.id > b.id) {
        return true;
    }

    return false;
}

bool criteriaEqualID(data_t a, data_t b)
{
    if (a.id == b.id) {
        return true;
    }

    return false;
}

bool criteriaEqualNameAndProduct(data_t a, data_t b)
{
    if (a.client == b.client && a.product == b.product) {
        return true;
    }

    return false;
}

int readbin(string filename, Node<data_t>* &ol_clients, Node<data_t>* &ol_id)
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    data_t data;
    while(file >> data) {
        insert(data, ol_clients, criteriaClients);
        insert(data, ol_id, criteriaIDAsc);
    }

    file.close();
    return 0;
}

void solveB(Node<data_t>* ol_id)
{
    cout << "Enter an ID number to retrieve its information, or a negative number to abort this operation." << endl << "ID: ";

    data_t aux;
    cin >> aux.id;

    while(aux.id >= 0) {
        Node<data_t>* result = nullptr;
        result = search(aux, ol_id, criteriaEqualID);

        if(result == nullptr) {
            cout << "Error. ID not found." << endl;
        } else {
            cout << result->data << endl;
        }

        cout << "ID: ";
        cin >> aux.id;
    }
}

void solveC(Node<data_t>* ol_clients, Node<data_t>* ol_id)
{
    cout << "Enter a CLIENT and a PRODUCT to delete all matching occurrences on both lists, enter EOF (Ctrl+D) to abort this operation." << endl;

    data_t aux;

    cout << "Client: ";
    while(cin >> aux.client) {
        cout << "Product: ";
        cin >> aux.product;

        bool status = false;
        while(remove(aux, ol_clients, criteriaEqualNameAndProduct)) {
            status = remove(aux, ol_id, criteriaEqualNameAndProduct);
        }

        if(status == true) {
            cout << endl << "Success. Matching pattern CLIENT-PRODUCT found." << endl << endl << "UPDATED DATA" << endl;
            stackPrint(ol_clients);
        } else {
            cout << endl << "Error. No matching pattern CLIENT-PRODUCT found." << endl;
        }

        cout << endl << "Client: ";
    }
}

int main(int argc, char *argv[])
{
    Node<data_t>* ol_clients = nullptr;
    Node<data_t>* ol_id = nullptr;

    readbin(DATA_FILE, ol_clients, ol_id);

    cout << "DATA ORDERED BY ID" << endl;
    stackPrint(ol_id);
    cout << endl;

    solveB(ol_id);
    cout << endl;

    cout << "DATA ORDERED BY CLIENTS" << endl;
    stackPrint(ol_clients);
    cout << endl;

    solveC(ol_clients, ol_id);

    stackErase(ol_clients);
    stackErase(ol_id);

    return 0;
}
