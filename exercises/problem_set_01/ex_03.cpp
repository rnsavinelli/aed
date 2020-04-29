/* ex_03.cpp
 *
 * Ingresar dos valores distintos en dos variables 'a' y 'b'.
 * Luego, el valor ingresado en 'a', pasarlo a 'b' y, el valor ingresado en 'b', pasarlo a 'a'.
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

using namespace std;

void values_get(double  *x, double *y);
void values_swap(double *x, double *y);
void values_print(double x, double y);

int main(int argc, char **argv)
{
	double a, b;

	values_get(&a, &b);
	values_swap(&a, &b);
	values_print(a, b);

	return 0;
}

void values_get(double *x, double *y)
{
	cout << "Enter a value for the FIRST variable: ";
	cin  >> (*x);
	cout << "Enter a value for the SECOND variable: ";
	cin  >> (*y);
}

void values_swap(double *x, double *y)
{
	double aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

void values_print(double x, double y)
{
	cout << "FIRST variable: " << x << endl;
	cout << "SECOND variable: " << y << endl;
}
