/* See LICENSE for license details. */

#include <iostream>
#include <fstream>
#include <cassert>

#define ERROR -1

using namespace std;

int data_load(string file_name, int buff[], const int length)
{
    assert(buff);

    ifstream file;

    file.open(file_name);

    if(!file.is_open()) {
        return ERROR;
    }

    for(int i = 0; i < length; i++) {
        file >> buff[i];
    }

    file.close();
    return 0;
}
