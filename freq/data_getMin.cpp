/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int
data_getMin(int buff[], const int size)
{
    assert(buff);

    int min = buff[0];
    int min_i = 0;

    for(int i = 1; i < size; i++) {
        if (buff[i] <= min) {
            min = buff[i];
            min_i = i;
        }
    }

    return min_i;
}
