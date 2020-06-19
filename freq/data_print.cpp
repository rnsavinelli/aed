/* See LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

void data_print(int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = " << buff[i] << endl;
    }
}
