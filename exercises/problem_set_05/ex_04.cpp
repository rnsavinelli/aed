/*
 * ex_04.cpp
 *
 * Dada los listas enlazadas programe una función que arme una nueva lista que
 * contenga la concatenación de los elementos de la primer lista, seguida de
 * los de la segunda.
 *   Variante A: las dos listas originales se pierden, es decir, nuestra
 *               rutina las vacía.
 *   Variante B: las dos listas originales quedan inalteradas.
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
linkedListsConcatA(Node<T>* &stack1, Node<T>* &stack2) {
    Node<T>* newstack = nullptr;

    while (stack1 != nullptr) {
        append(newstack, pop(stack1));
    }
    while (stack2 != nullptr) {
        append(newstack, pop(stack2));
    }

    return newstack;
}

template <typename T> Node<T>*
linkedListsConcatB(Node<T>* stack1, Node<T>* stack2) {
    Node<T>* newstack = nullptr;

    while (stack1 != nullptr) {
        append(newstack, stack1->data);
        stack1 = stack1->next;
    }
    while (stack2 != nullptr) {
        append(newstack, stack2->data);
        stack2 = stack2->next;
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

    stack3 = linkedListsConcatB(stack1, stack2);
    stackPrint(stack3);
    stackErase(stack3);

    cout << endl;

    stack3 = linkedListsConcatA(stack1, stack2);
    stackPrint(stack3);
    stackErase(stack3);

    return 0;
}
