/*
 * ex_04.cpp
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
linkedListsConcat(Node<T>* &stack1, Node<T>* stack2) {
	if (stackEmpty(stack1)) {
		stack1 = stack2;
	} else {
		Node<T>* s = stack1;
		while (s->next != nullptr)
			s = s->next;
		s->next = stack2;
	}
}

int
main(int argc, char *argv[]) {
    Node<string> *stack1 = nullptr;

    push(stack1, string("first"));
    append(stack1, string("second"));

    Node<string> *stack2 = nullptr;

    append(stack2, string("third"));
    append(stack2, string("fourth"));

    linkedListsConcat(stack1, stack2);

    stackPrint(stack1);

    return 0;
}
