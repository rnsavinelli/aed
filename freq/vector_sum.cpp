/* See ../LICENSE for license details. */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int
sum(vector<int> data)
{
    int result = 0;

    for (int element : data)
        result += element;

    return result;
}

float
mean(vector<int> data)
{
    return (float) sum(data) / data.size();
}
