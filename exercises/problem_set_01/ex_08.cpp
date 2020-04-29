/* ex_08.cpp
 *
 * Ingresar tres valores enteros que representan los valores de cada lado de un triángulo.
 * determinar e informar si el triángulo es equilátero (3 lados iguales), isósceles
 * (2 lados iguales), o escaleno (3 lados distinto).
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

void get_data(float *side_1, float *side_2, float *side_3);
string get_classification(float side_1, float side_2, float side_3);

int main(int argc, char **argv)
{
	float side_1, side_2, side_3;
	string result;

	get_data(&side_1, &side_2, &side_3);
	result = get_classification(side_1, side_2, side_3);

	cout << "Classification: " << result << endl;

	return 0;
}

void get_data(float *side_1, float *side_2, float *side_3)
{
	do {
		cout << "Enter a valid value for the FIRST side: ";
		cin  >> *side_1;
	} while(*side_1 <= 0);

	do {
		cout << "Enter a valid value for the SECOND side: ";
		cin  >> *side_2;
	} while(*side_2 <= 0);

	do {
		cout << "Enter a valid value for the THIRD side: ";
		cin  >> *side_3;
	} while(*side_3 <= 0);
}

string get_classification(float side_1, float side_2, float side_3)
{
	if (side_1 == side_2 && side_1 == side_3) {
		return "equilateral";
	}

	else if (side_1 == side_2 || side_1 == side_3 || side_2 == side_3) {
		return "isosceles";
	}

	else {
		return "scalene";
	}
}
