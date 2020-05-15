/* main.cpp
 *
 * Desarrolle la función inversa a la anterior, dada una fecha como un entero con formato
 * AAAAMMDD separarla en sus componentes día, mes y año y mostrarla en la función main a partir
 * de estas variables, con formato día/mes/año.
 * Variante: haga los ajustes necesarios para mostrar el resultado con formato DD/MM/AAAA . Es
 * decir que agregue ceros de ser necesario para que muestre, por ejemplo, 01/02/2019 en lugar
 * de 1/2/2019 .
 * Nota: la variante indicada NO es importante desde el punto de vista del curso, es para quienes
 * quieran profundizar un poco más en las particularidades de la biblioteca estándar de C++.
 * Pista: Usar #include <iomanip> y las funciones setw y setfill.
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
#include <iomanip>

#include "ex_03.hpp"

using namespace std;

int main(int argc, char **argv)
{
	date_t date_orig {0, 0, 0};
    date_t date_new  {0, 0, 0};

	date_get(&date_orig);
	cout << endl << "YYYYMMDD: " << setfill('0') << setw(8) << date_format(date_orig);
    date_new = date_copy(date_orig);
	cout << endl << "DD/MM/YYYY: " << date_format_alt(date_new) << endl;

	return 0;
}
