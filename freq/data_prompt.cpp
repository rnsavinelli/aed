#include <iostream>
#include <cassert>

using namespace std;

void data_prompt(int buff[], const int length)
{
    assert(buff);
    for(int i = 0; i < length; i++) {
        cout << "buff[" << i << "] = ";
        cin >> buff[i];
    }
}
