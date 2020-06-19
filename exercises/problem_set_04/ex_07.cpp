/* ex_07.cpp
 *
 * En un vector de 10 elementos encontrar los dos valores máximos, o sea el
 * más grande y el que le siga. Cargue el vector en la declaración.
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

#define BUFF_LENGTH 10

#define NDEBUG 1

using namespace std;

void data_prompt(int buff[], const int length)
{
	assert(buff);
	for(int i = 0; i < length; i++) {
		cout << "buff[" << i << "] = ";
		cin >> buff[i];
	}
}

void data_print(int buff[], const int length)
{
	assert(buff);
	for(int i = 0; i < length; i++) {
		cout << "buff[" << i << "] = " << buff[i] << endl;
	}
}

int get_max(int buff[], const int length)
{
	assert(buff);

	int max = buff[0];
	int max_i = 0;

	for(int i = 1; i < length; i++) {
		if (buff[i] >= max) {
			max = buff[i];
			max_i = i;
		}
	}

	return max_i;
}

int get_prevtomax(int buff[], const int length)
{
	assert(buff);

	int max = buff[0];
	int max_i = 0;
	int prevmax = buff[0];
	int prevmax_i = 0;

	for(int i = 1; i < length; i++) {
		if (buff[i] > max) {
			prevmax = max;
			prevmax_i = max_i;
			max = buff[i];
			max_i = i;
		}

		else if (buff[i] > prevmax) {
			prevmax = buff[i];
			prevmax_i = i;
		}
	}

	return prevmax_i;
}

int main(int argc, char **argv)
{
	int buff[BUFF_LENGTH] {};
	int pos;

	cout << ":: A buffer of lenght " << BUFF_LENGTH << " was created." << endl;
	data_prompt(buff, BUFF_LENGTH);

	pos = get_max(buff, BUFF_LENGTH);
	cout << ":: max: buff[" << pos << "] = " << buff[pos] << endl;

	pos = get_prevtomax(buff, BUFF_LENGTH);
	cout << ":: prevtomax: buff[" << pos << "] = " << buff[pos] << endl;

	return 0;
}
