/* ex_06.cpp
 *
 * Desarrolle una función que a partir de un parámetro entero calcule el factorial
 * del mismo usando recursión.
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

long int factorial(int n);
long int factorial_alt(int n);

int main(int argc, char **argv)
{
	int x {0};

	cout << "This program calculates the factorial of a number." << endl;
    do {
        cout << "Enter a positive number: ";
    	cin  >> x;
    } while (x < 0);

	cout << "Result: " << factorial_alt(x) << endl;

	return 0;
}

/* calculates the factorial of a number, if negative the returns -1 */
/* recursive */
long int factorial(int n)
{
    if (n > 0) {
        return n == 1 ? 1 : n * factorial(n-1);
    }

    else if (n < 0) {
        return -1;
    }
    /* else if n == 0,  return 1*/
    else return 1;
}

/* calculates the factorial of a number, if negative the returns -1 */
/* iterative */
long int factorial_alt(int n)
{
    if (n > 0) {
        int factorial {1};

        for(int i = 1; i <= n; i++) {
            factorial *= i;
        }

        return factorial;
    }

    else if (n < 0) {
        return -1;
    }

    else return 1;
}

