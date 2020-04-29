/* ex_07.cpp
 *
 * Leer 2 valores y mostrar el mayor de ellos, si son iguales mostrar cualquiera
 * de los dos.
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

void data_get(float *x, float *y);
void data_eval(float x, float y);

int main(int argc, char **argv)
{
	float x, y;

	data_get(&x, &y);
	cout << "For the values (x = " << x << ", y = " << y << "): " << endl;
	data_eval(x, y);

	return 0;
}

void data_get(float *x, float *y)
{
	cout << "Enter a value for the FIRST variable: ";
	cin  >> *x;
	cout << "Enter a value for the SECOND variable: ";
	cin  >> *y;
}

void data_eval(float x, float y)
{
	string statement;
	statement.clear();

	if(x > y) {
		statement = "MORE than";
	}

	else if (x < y) {
		statement = "LESS than";
	}

	else {
		statement = "EQUAL to";
	}

	cout << "[" << x << " is " << statement << " " << y << "]" << endl;
}
