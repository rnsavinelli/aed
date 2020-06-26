/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

void
bubbleSort(int buff[], unsigned const int size)
{
    assert(buff);
    bool disordered = true;

    for(int i = 0; i < size && disordered; i++) {
        disordered = false;
        for(int j = 0; j < size - 1; j++) {
            if(buff[j] > buff[j+1]) {
                swap(buff[j], buff[j+1]);
                disordered = true;
            }
        }
    }
}
