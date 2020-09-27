/*
 * ex_10.cpp
 *
 * Como el anterior, pero haga la variante b (preservando las listas
 * originales).
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

#define INVERSE   1
#define DEFAULT   0

using namespace std;

template <typename T> Node<T>*
linkedListsConcatB(Node<T>* stack1, Node<T>* stack2, bool order) {
    Node<T>* newstack = nullptr;

    if (order == INVERSE) {
        Node<T>* temp = stack1;
        stack1 = stack2;
        stack2 = temp;
        temp = nullptr;
    }

    while (!stackEmpty(stack1)) {
        append(newstack, stack1->data);
        stack1 = stack1->next;
    }
    while (!stackEmpty(stack2)) {
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

    Node<string> *stack3 = linkedListsConcatB(stack1, stack2, INVERSE);
    stackPrint(stack3);

    stackErase(stack1);
    stackErase(stack2);
    stackErase(stack3);

    return 0;
}
