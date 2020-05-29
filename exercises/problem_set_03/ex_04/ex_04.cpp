/* ex_04.cpp
 *
 * Crear un programa que permita concatenar dos archivos de texto.
 * Variantes: puede hacerlo de modo de tal de crear un archivo nuevo con la
 * concatenación y no alterar los archivos originales, o bien hacerlo de modo
 * tal que al segundo archivo se lo modifique concatenándole los contenidos
 * del primero.
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
#include <vector>

#define DATA_FILE_A "input_a.data"
#define DATA_FILE_B "input_b.data"
#define OUTPUT_FILE "output.data"

#define ERROR -1

using namespace std;

int data_load(vector<int> &data, string src);
int data_store(const vector<int> data, string dest);

int main(int argc, char **argv)
{
	vector<int> data_a, data_b, output;

	if (data_load(data_a, DATA_FILE_A) == ERROR) {
		cout << "An error was produced loading " << DATA_FILE_A << endl;
		cout << "Aborting execution." << endl;
	}

	if (data_load(data_b, DATA_FILE_B) == ERROR) {
		cout << "An error was produced loading " << DATA_FILE_B << endl;
		cout << "Aborting execution." << endl;
	}

    output.insert(output.begin(), data_a.begin(), data_a.end());
    output.insert(output.end(), data_b.begin(), data_b.end());

    data_store(output, OUTPUT_FILE);

	return 0;
}

int data_load(vector<int> &data, string src)
{
	ifstream file;
	int carry;

	file.open(src);
	if (!file.is_open()) {
		return ERROR;
	}

	file >> carry;

	while(!file.eof()) {
		data.push_back(carry);
		file >> carry;
	}

	file.close();

	return 0;
}

int data_store(const vector<int> data, string dest)
{
	ofstream file;

	file.open(dest);
	if (!file.is_open()) {
		return ERROR;
	}

	for(int element : data) {
		file << element << endl;
	}

	file.close();

	return 0;
}
