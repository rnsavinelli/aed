/* ex_03.cpp
 *
 * Dado un archivo que contienen una serie de números enteros, obtener a partir
 * de él dos
 * archivos. En el primero solo habrá números pares, y en el segundo solo
 * impares.
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
#define EVEN_DATA_PATH  "even.data"
#define ODD_DATA_PATH   "odd.data"

#define ERROR -1

using namespace std;

int data_load(vector<int> &data, string src);
int data_store(const vector<int> data, string dest);

void parity_split(vector<int> data, vector<int> &odd, vector<int> &even);

int main(int argc, char **argv)
{
    vector<int> data, odd, even;

    if (data_load(data, DATA_PATH) == ERROR) {
        cout << "An error was produced loading " << DATA_PATH << endl;
        cout << "Aborting execution." << endl;
    }

    parity_split(data, odd, even);

    if (data_store(odd, "odd.data") == ERROR) {
        cout << "An error was produced writing " << ODD_DATA_PATH << endl;
        cout << "Aborting execution." << endl;
    }

    if (data_store(even, "even.data") == ERROR) {
        cout << "An error was produced writing " << EVEN_DATA_PATH << endl;
        cout << "Aborting execution." << endl;
    }

	return 0;
}

int data_load(vector<int> &data, string src)
{
    ifstream file;
    int carry;

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

int data_store(const vector<int> data, string dest)
{
    ofstream file;

    file.open(dest);
    if (!file.is_open()) {
        return ERROR;
    }

    for(int element : data) {
        file << element << endl;
    }

    file.close();

    return 0;
}

void parity_split(const vector<int> data, vector<int> &odd, vector<int> &even) {
    for(int element : data) {
        if(element % 2 == 0) {
            even.push_back(element);
        }

        else odd.push_back(element);
    }
}
