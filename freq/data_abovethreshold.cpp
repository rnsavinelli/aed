/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int data_abovethreshold(float buff[], const int length, const float thr)
{
    assert(buff);
    int n = 0;

    for(int i = 0; i < length; i++)
        if(buff[i] > thr) n++;

    return n;
}
