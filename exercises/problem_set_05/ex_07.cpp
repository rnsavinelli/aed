/*
 * ex_07.cpp
 *
 * Dada una lista que contiene enteros programe una función que recorriendo la
 * misma devuelva el promedio (con decimales) de los valores guardados.
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

#include "./linkedLists/linkedLists.h"

using namespace std;

float
linkedIntListMean(Node<int>* stack) {
    int sum = 0;
    int size = 0;

    while(!stackEmpty(stack)) {
        size++;
        sum += stack->data;
        stack = stack->next;
    }

    return (size == 0) ? 0 : (float) sum/size;
}

int
main(int argc, char *argv[]) {
    Node<int> *stack = nullptr;

    push(stack, 7);
    push(stack, 45);
    push(stack, 924);

    cout << "Result: " << linkedIntListMean(stack) << endl;
    stackErase(stack);

    return 0;
}
