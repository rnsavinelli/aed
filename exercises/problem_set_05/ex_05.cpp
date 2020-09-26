/*
 * ex_05.cpp
 *
 * Similar al ejercicio anterior (programe solo la variante a) pero en lugar
 * de concatenar intercale.
 * Por ejemplo si la primer lista tiene 1, 2, 3 y la segunda lista tiene
 * 5, 6, 7, 8, 9 la lista resultante debe ser 1, 5, 2, 6, 3, 7, 8, 9.
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

template <typename T> Node<T>*
linkedListsConcatAlternated(Node<T>* &stack1, Node<T>* &stack2) {
    Node<T>* newstack = nullptr;
    while(!stackEmpty(stack1) && !stackEmpty(stack2)) {
        append(newstack, pop(stack1));
        append(newstack, pop(stack2));
    }

    while(!stackEmpty(stack1)) {
        append(newstack, pop(stack1));
    }

    while(!stackEmpty(stack2)) {
        append(newstack, pop(stack2));
    }

    return newstack;
}

int
main(int argc, char *argv[]) {
    Node<string> *stack1 = nullptr;

    push(stack1, string("first"));
    append(stack1, string("second"));

    Node<string> *stack2 = nullptr;

    append(stack2, string("third"));
    append(stack2, string("fourth"));

    Node<string> *stack3 = nullptr;

    stack3 = linkedListsConcatAlternated(stack1, stack2);

    stackPrint(stack3);

    stackErase(stack3);

    return 0;
}
