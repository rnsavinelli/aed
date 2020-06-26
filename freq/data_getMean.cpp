/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int
data_getMean(int buff[], const int size)
{
    assert(buff);

    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += buff[i];
    }

    return sum/size;
}
