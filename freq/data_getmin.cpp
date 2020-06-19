#include <iostream>
#include <cassert>

using namespace std;

int get_min(int buff[], const int length)
{
    assert(buff);

    int min = buff[0];
    int min_i = 0;

    for(int i = 1; i < length; i++) {
        if (buff[i] <= min) {
            min = buff[i];
            min_i = i;
        }
    }

    return min_i;
}
