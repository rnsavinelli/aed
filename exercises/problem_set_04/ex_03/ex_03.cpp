/* ex_03.cpp
 *
 * Cargar un vector con los promedios anuales (pueden tener decimales) de
 * las notas de 10 alumnos.
 * Informe el promedio de todas esas notas (calculado por una función)
 * y cuantos alumnos estuvieron por encima del promedio (calculado por otra
 * función).
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

#define BUFF_LENGTH 10
#define DATA_FILE "input.data"

#define LOG(type, msg) cout << "[" << type << "] " << msg << endl
#define ERROR -1
//#define NDEBUG 1

using namespace std;

int data_load(string file_name, float buff[], const int length)
{
    assert(buff);

    ifstream file;

    file.open(file_name);

    if(!file.is_open()) {
        return ERROR;
    }

    for(int i = 0; i < length; i++) {
        file >> buff[i];
    }

    file.close();
    return 0;
}

void data_print(float buff[], const int length)
{
    assert(buff);

    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = " << buff[i] << endl;
    }
}

float data_getmean(float buff[], const int length)
{
    assert(buff);

    float sum = 0;

    for(int i = 0; i < length; i++) {
        sum+=buff[i];
    }

    return sum/length;
}

int data_abovethreshold(float buff[], const int length, const float thr)
{
    assert(buff);
    int n = 0;

    for(int i = 0; i < length; i++)
        if(buff[i] > thr) n++;

    return n;
}

int main(int argc, char **argv)
{
	float buff[BUFF_LENGTH] {};
    float mean {};

    if(data_load(DATA_FILE, buff, BUFF_LENGTH)) {
        LOG("ERROR", "Failed to open the file.");
        LOG("STATUS", "Aborting execution.");
    }

    else {
        LOG("STATUS", "Data loaded successfully.");
        cout << "Printing read values:" << endl;
        data_print(buff, BUFF_LENGTH);
        mean = data_getmean(buff, BUFF_LENGTH);
        cout << "Data mean = " << mean << endl;
        cout << "Data values above the mean = "
             << data_abovethreshold(buff, BUFF_LENGTH, mean) << endl;
    }
	return 0;
}
