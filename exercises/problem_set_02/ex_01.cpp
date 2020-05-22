/* ex_01.cpp
 *
 * Desarrolle una función que reciba un año como parámetro y devuelva verdadero
 * si es bisiesto.
 * Nota: los años bisiestos son aquellos que son divisibles por 4 pero no por 100,
 * salvo que también sean divisibles por 400.
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

bool is_leap(int year)
{
	if ((year % 4) == 0 && (((year % 100) != 0) || (year % 400) == 0)) {
		return true;
	}

	else return false;
}

auto get_result(int year)
{
	return is_leap(year) ? "TRUE" : "FALSE";
}

int main(int argc, char **argv)
{
	int year {0};

	cout << "Enter a year to verify if is a leap year: ";
	cin  >> year;
	cout << "Result: " << get_result(year) << endl;

	return 0;
}
