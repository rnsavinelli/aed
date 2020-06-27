/* ex_14_alt.cpp
 *
 * Una empresa fabrica y distribuye sus productos mediante su flota de
 * vehículos. Cada vehículo tiene asignado un código que es un número entero
 * y los posibles valores van de 15 a 24. Se tiene un archivo en el cual, por
 * cada entrega realizada, se anota el código del vehículo que hizo.
 *
 * Se pide hacer un programa que con los datos del archivo informe que vehículo
 * (código) hizo la mayor cantidad de entregas.
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
#include <cassert>

#define N_VEHICLES      9
#define NUMBERING_SHIFT 15

#define DATA_FILENAME   "shipping.data"

//#define NDEBUG  1
#define ERROR   -1

using namespace std;

int
getMax(int buff[], unsigned const int size)
{
    assert(buff);

    int max = buff[0];
    int max_i = 0;

    for(unsigned int i = 1; i < size; i++) {
        if (buff[i] >= max) {
            max = buff[i];
            max_i = i;
        }
    }

    return max_i;
}

int
main(int argc, char **argv)
{
    int vehicles[N_VEHICLES] {0};
    ifstream file;

    file.open(DATA_FILENAME);
    if (!file.is_open()) {
        return ERROR;
    }

    while(!file.eof()) {
        int temp;
        file >> temp;
        vehicles[temp - NUMBERING_SHIFT]++;
    }

    file.close();

    int max = getMax(vehicles, N_VEHICLES);

    cout << "The vehicle with the most shipments was vehicle "
         <<  max + NUMBERING_SHIFT << " with " << vehicles[max]
         << " shipments." << endl;

    return 0;
}

