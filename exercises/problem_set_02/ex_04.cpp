/* ex_04.cpp
 *
 * Desarrolle una función que dada una temperatura ( float ) en grados fahrenheit
 * los convierta a grados celcius.
 * Nota: En fahrenheit el punto de congelación del agua es 32° y la temperatura de
 * ebullición del agua es 212°.
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

float fahrtocel(float fahrenheit);

int main(int argc, char **argv)
{
	int temperature = 0;

    	cout << "This program performs the temperature conversion from Fahrenheit to Celsius.";
    	cout << endl << "Enter a value: ";
	cin  >> temperature;

	cout << "Result: " << fahrtocel(temperature) << endl;

	return 0;
}

float fahrtocel(float fahrenheit) {
    return (5 * (fahrenheit - 32) / 9);
}
