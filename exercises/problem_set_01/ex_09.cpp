/* ex_09.cpp
 *
 * Ingresar 3 valores enteros, escribirlos primero en el orden que fueron
 * ingresados y luego mostrarlos ordenardos en forma creciente.
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

#define DATA_LENGTH 3

using namespace std;

void data_get(int *dataptr, int length);
void data_print(int *dataptr, int length);
void data_sort(int *dataptr, int length);

int main(int argc, char **argv)
{
	int dataptr[DATA_LENGTH];

	data_get(dataptr, DATA_LENGTH);

	cout << ":: Unsorted data:" << endl;
	data_print(dataptr, DATA_LENGTH);

	data_sort(dataptr, DATA_LENGTH);

	cout << ":: Sorted data:" << endl;
	data_print(dataptr, DATA_LENGTH);

	return 0;
}

void data_get(int *dataptr, int length)
{
	for(int i = 0; i < length; i++) {
		cout << "Enter a value for variable number " << i << ": ";
		cin  >> *(dataptr+i);
	}
}

void data_print(int *dataptr, int length)
{
	for(int i = 0; i < length; i++) {
		cout << "Variable " << i << ": " << *(dataptr+i) << endl;
	}
}

/* basic implementation of bubble sort */
void data_sort(int *dataptr, int length)
{
	int pass, hold;

	for (pass = 1; pass < length; pass++) {
		for (int i = 0; i < length - 1; i ++) {
			if (dataptr[i] > dataptr[i + 1]) {
				hold = dataptr[i];
				dataptr[i] = dataptr[i + 1];
				dataptr[i + 1] = hold;
			}
		}
	}
}
