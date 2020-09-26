/*
 * ex_03.cpp
 *
 * Copyright 2020 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
 *
 * Dada una pila programe un función rot (por rotar) tal que si la lista tiene
 * al menos 3 elementos ponga el tercero al tope y sino deje inalterada la
 * pila. Ejemplo, si la tiene 1, 2, 3, 4 luego de llamar a esta función la
 * pila quedará: 3, 1, 2, 4.
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
putThirdElementOnTop(Node<T>* &stack) {
    if (!stackEmpty(stack) && !stackEmpty(stack->next) && !stackEmpty(stack->next->next)) {
        T aux = stack->next->next->data;
        pop(stack->next->next);
        push(stack, aux);
    }
}

int
main(int argc, char *argv[]) {
    Node<string> *stack = nullptr;

    push(stack, string("first"));
    append(stack, string("second"));
    append(stack, string("third"));
    append(stack, string("fourth"));

    putThirdElementOnTop(stack);

    stackPrint(stack);

    stackErase(stack);

    return 0;
}
