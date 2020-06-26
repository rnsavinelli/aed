/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int
data_aboveThreshold(float buff[], unsigned const int size, const float thr)
{
    assert(buff);
    int n = 0;

    for(int i = 0; i < size; i++)
        if(buff[i] > thr) n++;

    return n;
}
