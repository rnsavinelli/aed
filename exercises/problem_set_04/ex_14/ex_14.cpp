/* ex_14.cpp
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
#include <vector>

#define N_VEHICLES      9
#define NUMBERING_SHIFT 15

#define DATA_FILENAME   "shipping.data"

//#define NDEBUG  1
#define ERROR   -1

using namespace std;

int
readFile(vector<int> &data, string filename)
{
    ifstream file;
    int carry;

    file.open(filename);
    if (!file.is_open()) {
        return ERROR;
    }

    while(!file.eof()) {
        file >> carry;
        data.push_back(carry);
    }

    file.close();

    return 0;
}

void
dataPrint(const vector<int> data)
{
    for(int element : data) {
        cout << element << endl;
    }
}

void
getMaxShippings(const vector<int> data, arr, size)
{

}

int
main(int argc, char **argv)
{
    int vehicles[N_VEHICLES] {};
    vector<int> shipping_records;

    if(readFile(shipping_records, DATA_FILENAME)) {
        cout << "ERROR: File not found!" << endl;
    }

    return 0;
}
