/* ex_02.cpp
 *
 * Dado un vector de double, armar una función que devuelva el promedio de
 * aquellos valores que superen una determinado parámetro (que se pasará a la
 * función).
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
#include <fstream>
#include <vector>

#define DATA_PATH       "input.data"
#define ERROR           -1

using namespace std;

int data_load(vector<double> &data, string src)
{
	ifstream file;
	double carry;

	file.open(src);
	if (!file.is_open()) {
		return ERROR;
	}

	file >> carry;

	while(!file.eof()) {
		data.push_back(carry);
		file >> carry;
	}

	file.close();

	return 0;
}

double data_thresholdmean(vector<double> &data, double thr) {
    double sum = 0;
    int n = 0;

    for(double element : data) {
        if(element > thr) {
            sum += element;
            n++;
        }
    }

    return sum/n;
}

int main(int argc, char **argv)
{
	vector<double> data;
    double thr;

    cout << "Data being read from " << DATA_PATH << endl;
	if (data_load(data, DATA_PATH) == ERROR) {
		cout << "An error was produced loading " << DATA_PATH << endl;
		cout << "Aborting execution." << endl;
	}

    cout << "Enter a threshold: ";
    cin >> thr;
    cout << "Mean = " << data_thresholdmean(data, thr) << endl;
}
