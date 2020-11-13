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

#define DATA_FILE "data/archivo.bin"

#define SHARE_NAME_SIZE 14

enum TERM_CODES {
    TERM_IMMEDIATE,
    TERM_24HS,
    TERM_48HS,
    TERM_72HS,
    TERM_96HS
};

typedef struct share {
    string name = "";
    int term = 0;
    int qty = 0;
    double price = 0;
} share_t;

typedef struct shareoperations {
    string name = "";
    int n_operations = 0;
    int n_topoperations = 0;
} shareoperations_t;

fstream& operator >> (fstream &fs, share_t& share)
{
	share.name = readstring(fs, SHARE_NAME_SIZE);
	fs.read(reinterpret_cast<char *>(&share.term), sizeof(share.term));
	fs.read(reinterpret_cast<char *>(&share.qty), sizeof(share.qty));
	fs.read(reinterpret_cast<char *>(&share.price), sizeof(share.price));
	return fs;
}

ostream& operator << (ostream &os, const shareoperations_t& share)
{
	os << share.name << ", " << share.n_operations << ", " << (float) share.n_topoperations * 100 / share.n_operations << "%";
	return os;
}

int criteriaOne(shareoperations_t a, shareoperations_t b) {
    if (a.name == b.name) {
        return 0;
    }

    return a.name > b.name ? 1 : -1;
}

int readbin(string filename, Node<shareoperations_t>* &ps, int (*criteria)(shareoperations_t, shareoperations_t))
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    share_t data;
    shareoperations_t aux = {"", 0, 0};
    while(file >> data) {
        aux.name = data.name;
        Node<shareoperations_t>* p = insert_unique(aux, ps, criteria);
        p->data.n_operations++;
        if(data.qty > 3000) {
            p->data.n_topoperations++;
        }
    }

    file.close();
    return 0;
}

int main(int argc, char *argv[])
{
    Node<shareoperations_t>* ps = nullptr;

    readbin(DATA_FILE, ps, criteriaOne);

    stackPrint(ps);
    stackErase(ps);

    return 0;
}
