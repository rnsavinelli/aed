/* ex_02.cpp
 *
 * Dado un No del 1 al 7 determinar (mostrar) el nombre del día de la semana que corresponde.
 * Si el nro está fuera de rango infórmelo como un error de ingreso de datos.
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
#include <string>

enum DAYS {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
	N_DAYS
};

using namespace std;

int main(int argc, char **argv)
{
	int day = 0;
	bool flag = false;

	string week[N_DAYS] {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	cout << "[STATUS] Enter a number between 1 to 7 to display what day of the week it is." << endl;

	do {
		if (flag == true) {
			cout << "[WARNING] Invalid input." << endl;
		}

		cout << "[STATUS] Input number (1-7): ";
		cin  >> day;

		day--;

	} while((flag = (day < MONDAY || day > SUNDAY)));

	cout << "[STATUS] " << week[day] << endl;
	return 0;
}
