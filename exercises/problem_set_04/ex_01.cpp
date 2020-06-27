/* ex_01.cpp
 *
 * Armar un vector con 10 valores enteros en la inicialización. Hallar la
 * sumatoria de los valores.
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
#define VERBOSE 1

using namespace std;

void data_prompt(long int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
#if VERBOSE
        cout << "buff[" << i << "] = ";
#endif
        cin >> buff[i];
    }
}

void data_print(long int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = " << buff[i] << endl;
    }
}

long int data_sum(long int buff[], const int length)
{
    assert(buff);
    long sum = 0;

    for(int i = 0; i < length; i++) {
        sum += buff[i];
    }

    return sum;
}

int main(int argc, char **argv)
{
    long int buff[BUFF_LENGTH] {};

#if VERBOSE
    cout << ":: A buffer of lenght " << BUFF_LENGTH << " was created." << endl;
#endif
    data_prompt(buff, BUFF_LENGTH);
#if VERBOSE
    cout << ":: Printing all buffer stored values." << endl;
    data_print(buff, BUFF_LENGTH);
    cout << ":: Stored values sum = ";
#endif
    cout << data_sum(buff, BUFF_LENGTH) << endl;

    return 0;
}
