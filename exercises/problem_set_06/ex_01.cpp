/*
 * ex_01.cpp
 *
 * Se tiene guardado, en un vector no ordenado, el listado de alumnos que
 * fueron seleccionadospara representar a la facultad en un congreso nacional
 * de ingeniería. De cada alumno se tiene elnombre, el legajo (entero) y su
 * promedio (double). Lamentablemente algunos alumnos nopodrán ir al congreso
 * por temas personales y han pedido que se los de baja.
 * Se tiene unsegundo vector no ordenado con los alumnos seleccionados que han
 * pedido ser dados de baja. Se pide:
 *
 * A.   listar los alumnos seleccionados ordenados por promedio en forma
 *      descendente y en casode empate por nombre en forma ascendente. La idea
 *      NO es ordenar el vector, sino insertarlo en una lista ordenada.
 *
 * B.   Luego mostrar sin orden los alumnos que han pedido darse de baja.
 *
 * C.   Por último volver a mostrar la lista ordenada de los alumnos
 *      seleccionados sin los quehayan sido dados de baja.
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
#include "linkedLists/linkedLists.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

typedef struct student {
    string name;
    int id;
    double mean;
} student_t;

ostream& operator << (ostream &os, const student_t& student)
{
	os << student.name << "\t" << student.id << "\t" << student.mean;
	return os;
}

bool criteriaStudentMeanDesc(student_t a, student_t b) {
    if (a.mean - b.mean < 0) {
        return true;
    } else if (a.mean == b.mean) {
        if (a.name >= b.name) {
            return true;
        }
    }

    return false;
}

bool criteriaStudentEqual(student_t a, student_t b) {
    if (a.name == b.name && a.id == b.id && a.mean == b.mean) {
        return true;
    }
    return false;
}

void solveA(Node<student_t>* &alumnae, student_t input[], int size, bool (*criteria)(student_t, student_t)){
    for(int i = 0; i < size; i++) {
        insert(input[i], alumnae, criteria);
    }
}

Node<student_t>* solveB(Node<student_t>* alumnae, student_t drop_outs[], int size, bool (*criteria)(student_t, student_t)) {
    Node<student_t>* filtered = nullptr;

    for(int i = 0; i < size; i++) {
        Node<student_t>* e = search(drop_outs[i], alumnae, criteria);
        if (!stackEmpty(e)) {
            append(filtered, e->data);
        }
    }

    return filtered;
}

void solveC(Node<student_t>* &alumnae, student_t input[], int size, bool (*criteria)(student_t, student_t)){
    for(int i = 0; i < size; i++) {
        remove(input[i], alumnae, criteria);
    }
}

int main(int argc, char *argv[]) {
    /* problem A */
    student_t input1[] = {
        "Maria", 721, 8.4,
        "Pedro", 847, 7.2,
        "Ana", 614, 9.1,
        "Jose", 578, 8.9,
        "Juan", 927, 8.4,
        "Unai", 325, 8.1,
        "Ramon", 418, 8.4,
        "Elaia", 892, 9.6,
        "Carlos", 733, 8.5
    };

    Node<student_t> *alumnae = nullptr;

    solveA(alumnae, input1, ARRAY_SIZE(input1), criteriaStudentMeanDesc);
    stackPrint(alumnae);
    cout << endl;

    /* problem B */
    student_t input2[] = {
        "Pedro", 847, 7.2,
        "Ramon", 418, 8.4,
        "Unai", 325, 8.1
    };

    Node<student_t> *dropouts = nullptr;

    dropouts = solveB(alumnae, input2, ARRAY_SIZE(input2), criteriaStudentEqual);
    stackPrint(dropouts);
    cout << endl;

    /* problem C */
    solveC(alumnae, input2, ARRAY_SIZE(input2), criteriaStudentEqual);
    stackPrint(alumnae);

    /* exit routine */
    stackErase(alumnae);
    stackErase(dropouts);

    return 0;
}
