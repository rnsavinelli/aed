#include <iostream>
#include <fstream>
#include <vector>

#define ERROR -1

using namespace std;

int data_store(const vector<int> data, string dest)
{
	ofstream file;

	file.open(dest);
	if (!file.is_open()) {
		return ERROR;
	}

	for(int element : data) {
		file << element << endl;
	}

	file.close();

	return 0;
}
