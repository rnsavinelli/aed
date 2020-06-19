/* ex_05.cpp
 *
 * Se tiene un vector de 8 elementos enteros. Sus valores deben cargarse por
 * consola en forma estrictamente creciente, verificando y volviendo a pedir
 * un valor si no cumple la condición (Arme una función de carga con
 * verificación).
 * Programe una función que encuentre, cuál es la máxima diferencia entre
 * dos elementos sucesivos. Informe el valor de la misma y entre que
 * elementos se produce.
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

void data_get(int buff[], const int length)
{
    assert(buff);

    bool err_flag = false;

    cout << "buff[0] = ";
    cin  >> buff[0];

    for(int i = 1; i < length; i++) {
        do {
            if (err_flag) {
                cout << "Error! "
                     << "Make sure buff[" << i << "] > buff[" << i-1 << "]"
                     << endl;
            }
            cout << "buff[" << i << "] = ";
            cin  >> buff[i];
        } while((err_flag = (buff[i] <= buff[i-1])));
    }
    cout << endl;
}

void data_print(int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = " << buff[i] << endl;
    }
}

int data_getmaxdiff(int buff[], const int length)
{
    assert(buff);

    if(length <= 1)
        return buff[0];

    int fmax = 0;

    for(int i = 0; i < length - 1; i++) {
        if((buff[i+1] - buff[i]) > (buff[1+fmax] - buff[fmax])) {
            fmax = i;
        }
    }

    return fmax;
}

int main(int argc, char **argv)
{
    int buff[BUFF_LENGTH] {};
    int fmax = 0;

    cout << ":: Fill-in an array of " << BUFF_LENGTH << " ints with "
         << "strictly increasing values:" << endl;
    data_get(buff, BUFF_LENGTH);
    cout << ":: Stored values:" << endl;
    data_print(buff, BUFF_LENGTH);

    cout << endl << ":: Printing maximum diff value:" << endl;
    fmax = data_getmaxdiff(buff, BUFF_LENGTH);
    cout << "buff[" << (fmax + 1) << "] - "
         << "buff[" << fmax << "] = " << buff[fmax + 1] - buff[fmax]
         << endl;

	return 0;
}
