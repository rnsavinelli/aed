/* See ../LICENSE for license details. */

#include <iostream>
#include <fstream>
#include <cassert>

#define ERROR -1

using namespace std;

int
data_loadFromFile(string file_name, int buff[], unsigned const int size)
{
    assert(buff);

    ifstream file;

    file.open(file_name);

    if(!file.is_open()) {
        return ERROR;
    }

    for(int i = 0; i < size; i++) {
        file >> buff[i];
    }

    file.close();
    return 0;
}
