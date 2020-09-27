/*
 * ex_08.cpp
 *
 *  Dada una lista que contiene enteros programe una función que devuelva:
 *   1. Variante a: el mayor valor en la lista
 *   2. Variante b: un puntero al nodo que contiene el mayor elemento
 *                  en la lista.
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

int
linkedIntListMaxA(Node<int>* stack) {
    if(stackEmpty(stack)) {
        return 0;
    }

    int max = stack->data;
    stack = stack->next;

    while(!stackEmpty(stack)) {
        if(stack->data > max) {
            max = stack->data;
        }
        stack = stack->next;
    }

    return max;
}

Node<int> *
linkedIntListMaxB(Node<int>* stack) {
    if(stackEmpty(stack)) {
        return nullptr;
    }

    Node<int>* max = stack;
    stack = stack->next;

    while(!stackEmpty(stack)) {
        if(stack->data > max->data) {
            max = stack;
        }
        stack = stack->next;
    }

    return max;
}

int
main(int argc, char *argv[]) {
    Node<int> *stack = nullptr;

    push(stack, 1532);
    push(stack, -78);
    push(stack, 453);
    push(stack, 924);
    push(stack, -8);

    cout << "Result A: " << linkedIntListMaxA(stack) << endl;
    cout << "Result B: " << linkedIntListMaxB(stack)->data << endl;
    stackErase(stack);

    return 0;
}
