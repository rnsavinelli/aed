/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

void swap(int buff[], const int i, const int j)
{
	int foo = buff[i];

	buff[i] = buff[j];
	buff[j] = foo;
}

void data_sort(int buff[], const int length)
{
	assert(buff);
    bool disordered = true;

	for(int i = 0; i < length && disordered; i++) {
        disordered = false;
		for(int j = 0; j < length - 1; j++) {
			if(buff[j] > buff[j+1]) {
				swap(buff, j, j+1);
                disordered = true;
			}
		}
	}
}
