/* See LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

int linsearch(int key, int buff[], const int length)
{
    for(int i=0; i < length; i++)
        if(buff[i] == key)
            return i;

    return -1; /* if no occurrences */
}
