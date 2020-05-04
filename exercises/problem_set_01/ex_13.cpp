/* ex_13.cpp
 *
 * Cuenta la leyenda de la creación del ajedrez que el sabio pidió al rey como recompensa 1 grano
 * de arroz por el primer casillero, 2 por el segundo, 4 por el tercero, etc. Calcule el total de
 * granos de arroz en el tablero. Nota: la idea es armar un ciclo que acumule el arroz de cada
 * casillero, sin embargo por fórmula sabemos que la cantidad pedida es 2 64 -1 por ello deberá usar
 * variables tipo unsigned long si su sistema es de 64 bits o unsigned long long si su
 * sistema es de 32 bits para poder alojar el valor requerido en forma correcta.
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
#include <cmath>

#define TOTAL_SQUARES 64

using namespace std;

unsigned long get_rice();

int main(int argc, char **argv)
{
	unsigned long rice;

	rice = get_rice();
	cout << rice << endl;

	return 0;
}

unsigned long get_rice()
{
	unsigned long rice = 0;

	for (int i = 0 ; i < TOTAL_SQUARES ; i++) {
		rice += (unsigned long) pow(2.0, (double) i);
	}

	return rice;
}
