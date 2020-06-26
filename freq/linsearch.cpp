/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int
linsearch(int key, int buff[], unsigned const int size)
{
    for(int i=0; i < size; i++)
        if(buff[i] == key)
            return i;

    return -1; /* if no occurrences */
}
