/* ex_07.cpp
 *
 * La sucesión de Fibonacci se define como :
 * f_0 = 0
 * f_1 = 1
 * f_n = f_(n-1) + f_(n-2)
 * Desarrolle una función que dando n, calcule el enésimo término de la sucesión usando
 * recursión.
 * Variante: use iteración en lugar de recursión.
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

long int fibonacci(int n);
long int fibonacci_alt(int n);

int main(int argc, char **argv)
{
	int x {0};

    do {
    	cout << "Enter a positive number to calculate the its Fibonacci: ";
	    cin  >> x;

        if (x < 0) {
            cout << "Invalid input." << endl;
        }
    } while(x < 0);

	//cout << "Iterative result: " << fibonacci_alt(x) << endl;
	cout << "Recursive result: " << fibonacci(x) << endl;

	return 0;
}

long int fibonacci(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }

    else return fibonacci(n-1) + fibonacci(n-2);
}

long int fibonacci_alt(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }

    int fib {0}, fa {1}, fb {1};

    while(n > 2) {
        fib = fa + fb;
        fa = fb;
        fb = fib;
        n--;
    }

    return fib;
}
