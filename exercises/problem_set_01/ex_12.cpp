/* ex_12.cpp
 *
 * Ingresar un número cualquiera y determinar si es positivo o no.
 * Repetir en un ciclo hasta que el nro ingresado sea cero.
 * Nota: utilice el operador ?:
 * 1. Variante a: considere el cero como positivo
 * 2. Variante b: En caso de ingresar cero no emita ningún mensaje,
 *                simplemente finalice el programa
 *
 * Copyright (c) 2020 Savinelli Roberto Nicolás <rsavinelli@est.frba.utn.edu.ar>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	float x;

	do {
		cout << "Enter an number: ";
		cin  >> x;

		/* Variante a */
		(x >= 0) ? cout << "Positive" << endl : cout << "Negative" << endl;

		/* Variante b */
		/*
		if(x == 0) {
		    break;
		} else {
		    (x > 0) ? cout << "Positive" << endl : cout << "Negative" << endl;
		}
		*/

	} while(x != 0);

	return 0;
}
