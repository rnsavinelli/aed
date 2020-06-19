/* See LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int get_max(int buff[], const int length)
{
    assert(buff);

    int max = buff[0];
    int max_i = 0;

    for(int i = 1; i < length; i++) {
        if (buff[i] >= max) {
            max = buff[i];
            max_i = i;
        }
    }

    return max_i;
}
