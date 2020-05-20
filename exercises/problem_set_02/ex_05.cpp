/* ex_05.cpp
 *
 * Desarrolle una función que calcule la sumatoria de Gauss. Dicha función recibe
 * como parámetro el entero hasta el que se quiere calcular.
 * Nota: El ejercicios tiene por objetivo practicar las iteraciones, no usar la
 * fórmula de Gauss.
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

int sigma(int n);
int sigma_alt(int n);

int main(int argc, char **argv)
{
	int x {0};

	cout << "This program adds the numbers from 1 to n." << endl;
	cout << "Enter a value for n: ";
	cin  >> x;

	cout << "Result: " << sigma(x) << endl;

	return 0;
}

int sigma(int n)
{
	return (n <= 0) ? 0 : n + sigma(n-1);
}

int sigma_alt(int n)
{
	int sum {0};

	for (int i {1}; i <= n; i++) {
		sum += i;
	}

	return sum;
}
