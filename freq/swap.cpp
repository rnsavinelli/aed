/* See ../LICENSE for license details. */

#include <iostream>

using namespace std;

void swap(int buff[], const int i, const int j)
{
    int foo = buff[i];

    buff[i] = buff[j];
    buff[j] = foo;
}
