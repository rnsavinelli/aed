/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int
data_getMax(int buff[], unsigned const int size)
{
    assert(buff);

    int max = buff[0];
    int max_i = 0;

    for(int i = 1; i < size; i++) {
        if (buff[i] >= max) {
            max = buff[i];
            max_i = i;
        }
    }

    return max_i;
}
