/* See ../LICENSE for license details. */

#include <iostream>
#include <cassert>

using namespace std;

void
data_prompt(int buff[], unsigned const int size)
{
    assert(buff);

    for(int i = 0; i < size; i++) {
        cout << "buff[" << i << "] = ";
        cin >> buff[i];
    }
}
