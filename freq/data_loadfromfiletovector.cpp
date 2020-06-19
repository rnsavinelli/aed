#include <iostream>
#include <fstream>
#include <vector>

#define ERROR -1

using namespace std;

int data_load(vector<double> &data, string src)
{
	ifstream file;
	double carry;

	file.open(src);
	if (!file.is_open()) {
		return ERROR;
	}

	file >> carry;

	while(!file.eof()) {
		data.push_back(carry);
		file >> carry;
	}

	file.close();

	return 0;
}
