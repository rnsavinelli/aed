/* ex_02.cpp
 *
 * Arme un programa que lea cantidades reales de un archivo. Informe por pantalla
 * cual es el menor valor y en que orden se encontraba (ordinal del valor en la secuencia)
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

#define DATA_PATH "./input.data"
#define ERROR -1

using namespace std;

int data_load(vector<float> &data, string src);
int min_index(vector<float> data);

int main(int argc, char **argv)
{
	vector<float> data;
	int position = 0;

	if (data_load(data, DATA_PATH) == ERROR) {
		cout << "An error was produced.." << endl;
		cout << "Aborting execution." << endl;
	}

	position = min_index(data);

	cout << "Value: " << data[position] << endl;
	cout << "Position: " << position << endl;

	return 0;
}

int data_load(vector<float> &data, string src)
{
	ifstream file;
	float carry;

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

int min_index(vector<float> data)
{
	float temp = data.front();
	int index = 0;

	for(float &element : data) {
		if(element < temp) {
			temp = element;
			index = &element - &data.front();
		}
	}

	return index;
}
