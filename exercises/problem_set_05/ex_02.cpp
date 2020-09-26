/*
 * ex_02.cpp
 *
 * Dada una pila programe una función swap que inverta los dos elementos tope.
 * Si la pila tiene 1, 2, 3 luego de llamar a esta función tendrá 2, 1 , 3.
 * Si la pila tiene menos de dos elementos la función la deja inalterada.
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

template <typename T> void
swapFirstTwoElements(Node<T>* &stack) {
    if (!stackEmpty(stack) && !stackEmpty(stack->next)) {
        T aux;
        aux = stack->data;
        stack->data = stack->next->data;
        stack->next->data = aux;
    }
}

int
main(int argc, char *argv[]) {
    Node<string> *stack = nullptr;

    push(stack, string("first"));
    append(stack, string("second"));
    append(stack, string("third"));

    swapFirstTwoElements(stack);

    stackPrint(stack);

    stackErase(stack);

    return 0;
}
