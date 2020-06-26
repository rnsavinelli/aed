/* ex_13.cpp
 *
 * Defina y de valores a una matriz de enteros de 5 filas y 4 columnas. Llame
 * a una función que acepte matrices de tipo entero con 4 columnas (cantidad
 * de filas a pasar como parámetro) y devuelva en que fila y columna se
 * encuentra el menor elemento de la matriz.
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

#define ROWS  5
#define COLS  4

//#define NDEBUG  1

struct position {
    unsigned int x;
    unsigned int y;
};

using namespace std;

void
dataPrompt(double m[][COLS], unsigned const int rows)
{
	assert(m);

	for(unsigned int i = 0; i < rows; i++) {
        for(unsigned int j = 0; j < COLS; j++) {
		    cout << "m[" << i << "][" << j << "] = ";
    		cin >> m[i][j];
	    }

        if (i != rows - 1) cout << endl;
    }
}

struct position
dataMin(double m[][COLS], unsigned const int rows)
{
	assert(m);

    struct position min {0, 0};
    double minval = m[0][0];

	for(unsigned int i = 0; i < rows; i++) {
        for(unsigned int j = 0; j < COLS; j++) {
            if (m[i][j] < minval) {
                minval = m[i][j];
                min.x = i;
                min.y = j;
            }
        }
    }

    return min;
}

void
dataPrint(double m[][COLS], unsigned const int rows)
{
	assert(m);

	for(unsigned int i = 0; i < rows; i++) {
        for(unsigned int j = 0; j < COLS; j++) {
	    	cout << "m[" << i << "][" << j << "] = " << m[i][j] << endl;
        }

        if (i != rows - 1) cout << endl;
	}
}

int
main(int argc, char **argv)
{
	double m[ROWS][COLS] {};
    struct position min {0, 0};

    cout << ":: Fill in a matrix of doubles with " << ROWS << " rows and "
         << COLS << " columns:" << endl;
    dataPrompt(m, ROWS);

    min = dataMin(m, ROWS);
    cout << endl << ":: Minimum = "
         << "m[" << min.x << "][" << min.y << "] = "
         << m[min.x][min.y] << endl;

	return 0;
}
