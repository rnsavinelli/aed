/* ex_05_alt.cpp
 *
 * Crear un programa que permita generar un archivo de texto a partir de palabras
 * ingresadas por teclado, donde haya como máximo 80 caracteres por renglón. Pero
 * deberá evitarse cortar palabras.
 *
 * Nota: para averiguar cuantos caracteres tiene un string, puede usarse la función size, por
 * ejemplo, si declaré str cadena; luego puedo obtener el largo con cadena.size();
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
#include <fstream>

#define FILE_NAME "output.txt"
#define SIZE_LIMIT 80
#define BLANKSPACE_SIZE 1

using namespace std;

int main(int argc, char **argv)
{
	ofstream file;
	string word, buffer;
	int linesize = 0;

	file.open(FILE_NAME);
	if(!file.is_open()) {
		cout << "ERROR: Failed to open the file!" << endl;
		return -1;
	}

	while(cin >> word) {
		if((linesize += word.size()) >= SIZE_LIMIT) {
			buffer += '\n';
			linesize = word.size();
		}

		buffer += (word + " ");
		linesize += BLANKSPACE_SIZE;
	}

	file << buffer;
	file.close();
	return 0;
}
