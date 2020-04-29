/* ex_05.cpp
 *
 * Dadas las medidas de dos ángulos de un triángulo, determinar la medida del
 * tercero e informar el resultado.
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

/* From Wikipedia:
 *
 * Three given angles form a triangle if and only if both of these conditions hold:
 * (a) each of the angles is positive
 * (b) the angles sum to 180 degrees
 *
 * https://en.wikipedia.org/wiki/Triangle#Conditions_on_the_angles
 *
 * Therefore, we define:
 */

#define MAX_VALUE 180

void get_two(float *alpha, float *beta);
float compute_third(float alpha, float beta);

using namespace std;

int main(int argc, char **argv)
{
	float alpha, beta, gamma;

	get_two(&alpha, &beta);
	gamma = compute_third(alpha, beta);

	cout << "THIRD angle: " << gamma << endl;

	return 0;
}

void get_two(float *alpha, float *beta)
{
	do {
		cout << "Enter a valid value for the FIRST angle: ";
		cin  >> *alpha;
	} while((*alpha <= 0) || (*alpha >= MAX_VALUE));

	do {
		cout << "Enter a valid value for the SECOND angle: ";
		cin  >> *beta;
	} while((*beta <= 0) || (*beta >= (MAX_VALUE - *alpha)));
}

float compute_third(float alpha, float beta)
{
	return (float) MAX_VALUE - alpha - beta;
}
