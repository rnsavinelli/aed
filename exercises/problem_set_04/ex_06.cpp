/* ex_06.cpp
 *
 * En un vector con 10 elementos enteros que tiene valores repetidos encuentre:
 *  1. La posición del primer valor mínimo (recuerde: puede haber más de uno).
 *  2. La posición del último valor mínimo.
 *  3. Cuantas veces se repite el valor mínimo.
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

//#define NDEBUG 1

#define M_FIRST 1
#define M_LAST  2
#define N_MINS  0

using namespace std;

void
data_get(int buff[], const int length)
{
    assert(buff);

    cout << "buff[0] = ";
    cin  >> buff[0];

    for(int i = 1; i < length; i++) {
        cout << "buff[" << i << "] = ";
        cin  >> buff[i];
    }
    cout << endl;
}

int
min_get(int buff[], const int length, const int function)
{
    assert(buff);

    int min = buff[0];
    int n = 0;

    switch(function) {
    case M_FIRST:
        for(int i = 1; i < length; i++) {
            if(buff[i] < min) {
                min = buff[i];
                n = i;
            }
        }
        break;

    case M_LAST:
        for(int i = 1; i < length; i++) {
            if(buff[i] <= min) {
                min = buff[i];
                n = i;
            }
        }
        break;

    case N_MINS:
    default:
        for(int i = 1; i < length; i++) {
            if(buff[i] <= min) {
                min = buff[i];
            }
        }

        for(int i = 0; i < length; i++) {
            if(buff[i] == min) {
                n++;
            }
        }
        break;
    }

    return n;
}

int
main(int argc, char **argv)
{
    int buff[BUFF_LENGTH] {};
    int position = 0;

    cout << "Fill-in an array of " << BUFF_LENGTH << " ints:" << endl;
    data_get(buff, BUFF_LENGTH);

    cout << "First minimum: ";
    position = min_get(buff, BUFF_LENGTH, M_FIRST);
    cout << "buff[" << position << "] = " << buff[position] << endl;

    cout << "Last minimum: ";
    position = min_get(buff, BUFF_LENGTH, M_LAST);
    cout << "buff[" << position << "] = " << buff[position] << endl;

    cout << "Number of minima: "
         << min_get(buff, BUFF_LENGTH, N_MINS) << endl;

    return 0;
}
