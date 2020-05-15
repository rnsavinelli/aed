/* main.cpp
 *
 * Ingrese una fecha como 3 enteros para día, mes y año. Pase estos datos a una función que
 * devuelva un entero que represente la misma fecha pero con formato AAAAMMDD .
 * Variante: Ingrese los mismos datos pero de modo tal que el operador pueda ingresar en
 * formato fecha, es decir, algo del estilo 25/5/2019.
 * Nota: la variante indicada NO es importante desde el punto de vista del curso, es para quienes
 * quieran profundizar un poco más en las particularidades de la biblioteca estándar de C++.
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

#include "ex_02.hpp"

using namespace std;

int main(int argc, char **argv)
{
    date_t date {0, 0, 0};

    date_get(&date);

    cout << endl << "YYYYMMDD: " << setfill('0') << setw(8) << date_format(date) << endl;
    cout << "DD/MM/YYYY: " << date_format_alt(date) << endl;

	return 0;
}
