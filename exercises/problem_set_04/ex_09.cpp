/* ex_09.cpp
 *
 * Ingrese en un vector 10 enteros. Muéstrelos en el orden ingresado.
 * Ordénelos en forma ascendente y muéstrelos ordenados.
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
#define N_DEBUG     1

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

void swap(int buff[], const int i, const int j)
{
    int foo = buff[i];

    buff[i] = buff[j];
    buff[j] = foo;
}

void data_sort(int buff[], const int length)
{
    assert(buff);
    bool disordered = true;

    for(int i = 0; i < length && disordered; i++) {
        disordered = false;
        for(int j = 0; j < length - 1; j++) {
            if(buff[j] > buff[j+1]) {
                swap(buff, j, j+1);
                disordered = true;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int buff[BUFF_LENGTH] {};

    cout << ":: An array of lenght " << BUFF_LENGTH << " was created." << endl;
    data_prompt(buff, BUFF_LENGTH);

    cout << endl << ":: Printing all stored values." << endl;
    data_print(buff, BUFF_LENGTH);

    data_sort(buff, BUFF_LENGTH);
    cout << endl << ":: Data has been sorted." << endl;
    cout << ":: Printing all stored values." << endl;
    data_print(buff, BUFF_LENGTH);

    return 0;
}
