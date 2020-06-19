/* ex_08.cpp
 *
 * Se pide ingresar por teclado 8 valores que se cargarán en un vector, pero
 * se controlará que todos los valores sean distintos. Si el valor ingresado
 * ya se encuentra en los cargados previamente, vuelva a solicitar el valor
 * para esa posición.
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
#include <cassert>

#define BUFF_LENGTH 8
#define NDEBUG 1

using namespace std;

int linsearch(int key, int buff[], const int length)
{
	for(int i=0; i < length; i++)
		if(buff[i] == key)
			return i;

	return -1; /* if no occurrences */
}

void data_prompt(int buff[], const int length)
{
	assert(buff);

	bool flag = false;

	for(int i = 0; i < length; i++) {
		do {
			cout << "buff[" << i << "] = ";
			cin >> buff[i];

			for(int j = 0; j < i; j++) {
				if(buff[j] == buff[i]) {
					cout << endl << "[ERROR]\tVerify your input and try again:"
					     << endl;
					cout << "\tbuff[" << i << "] = buff[" << j
					     << "] = " << buff[j] << endl << endl;
					flag = true;
					break;
				}

				else
					flag = false;
			}
		} while(flag);
	}
}

void data_print(int buff[], const int length)
{
	assert(buff);
	for(int i = 0; i < length; i++) {
		cout << "buff[" << i << "] = " << buff[i] << endl;
	}
}

int main(int argc, char **argv)
{
	int buff[BUFF_LENGTH] {};

	cout << ":: Fill-in the buffer with " << BUFF_LENGTH
	     << " different values." << endl << endl;
	data_prompt(buff, BUFF_LENGTH);
	cout << endl << ":: Stored values:" << endl << endl;
	data_print(buff, BUFF_LENGTH);

	return 0;
}
