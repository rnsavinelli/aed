/* ex_04.cpp
 *
 * Dado un vector de 10 enteros inicializado con datos al definirlo, programe
 * una función que permita encontrar la posición del valor máximo. Usarla
 * para informar cuál es el máximo y en que posición del vector se encuentra.
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

void data_print(int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = " << buff[i] << endl;
    }
}

/* returns the position of the maximum value inside an array */
int data_getmax(int buff[], const int length)
{
    assert(buff);
    int max_val = buff[0];
    int max_pos = 0;

    for(int i = 1; i < length; i++) {
        if(buff[i] > max_val) {
            max_val = buff[i];
            max_pos = i;
        }
    }

    return max_pos;
}

int main(int argc, char **argv)
{
	int buff[BUFF_LENGTH]; /* I will make use of uninitialized values */
    int max_position {};

    cout << ":: Printing all initialized values:" << endl;
    data_print(buff, BUFF_LENGTH);

    cout << ":: Printing maximum value:" << endl;
    max_position = data_getmax(buff, BUFF_LENGTH);
    cout << "buff[" << max_position << "] = " << buff[max_position]
         << endl;

	return 0;
}
