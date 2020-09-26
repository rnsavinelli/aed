/*
 * ex_06.cpp
 *
 * Dado un string programe la función esCapicua que devuelve true si la cadena
 * ingresada se lee igual la derecho que al revés. Esta función debe usar las
 * funciones de lista que estamos practicando.
 *
 * Variante: para poder comprobar frases palíndromas es necesario ignorar los
 *           espacios en blanco.
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
#include <algorithm>

#include "./linkedLists/linkedLists.h"

using namespace std;

template <typename T> bool
isPalindrome(Node<T>* stack) {
    Node<T>* dummy = stack;
    Node<T>* reverse = nullptr;

    while(!stackEmpty(dummy)) {
        push(reverse, dummy->data);
        dummy = dummy->next;
    }
    while(!stackEmpty(stack) && !stackEmpty(reverse)) {
        if(stack->data != reverse->data) {
            return false;
        } else {
            stack = stack->next;
            pop(reverse);
        }
    }

    return true;
}

void
loadStringToStack(Node<char>* &stack, string text) {
    for(int i = text.size() - 1; i >= 0; i --) {
        push(stack, text[i]);
    }
}

int
main(int argc, char *argv[]) {
    Node<char> *stack = nullptr;
    string textinput;

    cout << "Enter a word or phrase: ";
    getline(cin, textinput);
    transform(textinput.begin(), textinput.end(),
        textinput.begin(), ::tolower);
    loadStringToStack(stack, textinput);

    cout << "Result: " << isPalindrome(stack) << endl;
    stackErase(stack);

    return 0;
}
