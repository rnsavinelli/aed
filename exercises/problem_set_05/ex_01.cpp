/*
 * ex_01.cpp
 *
 * Dada una pila programe una función dup (por duplicar) que reciba la pila y
 * duplique el elemento que está en el tope (a menos que la pila esté vacía).
 * Por ejemplo si la pila un 1 al tope seguido más abajo de un 2 (Notación: 1,
 * 2) luego de invocar esta función debe tener 1, 1, 2.
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
dupFirstElement(Node<T>* &stack) {
    if (!stackEmpty(stack)) {
        push(stack, stack->data);
    }
}

int main(int argc, char *argv[]) {
    Node<int> *stack = nullptr;

    push(stack, 1);
    append(stack, 2);

    dupFirstElement(stack);

    stackPrint(stack);

    stackErase(stack);

    return 0;
}
