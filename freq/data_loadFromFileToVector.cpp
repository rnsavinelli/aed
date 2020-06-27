/* See ../LICENSE for license details. */

#include <iostream>
#include <fstream>
#include <vector>

#define ERROR -1

using namespace std;

int
data_loadFromFile(vector<double> &data, string src)
{
    ifstream file;
    double carry;

    file.open(src);
    if (!file.is_open()) {
        return ERROR;
    }

    while(!file.eof()) {
        data.push_back(carry);
        file >> carry;
    }

    file.close();

    return 0;
}
