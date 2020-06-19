#include <iostream>
#include <cassert>

using namespace std;

int data_getmean(int buff[], const int length)
{
    assert(buff);

    int sum = 0;

    for(int i = 0; i < length; i++) {
        sum+=buff[i];
    }

    return sum/length;
}
