#include <iostream>

using namespace std;

const int nsuc = 8;
const int ngus = 6;

int
minimo(int vec[], const int ngus)
{
    int min = vec[0];
    int min_i = 0;

    for(int i = 1; i < ngus; i++) {
        if (vec[i] <= min) {
            min = vec[i];
            min_i = i;
        }
    }

    return min_i;
}

int
main(void)
{
	int vec[ngus] {38, 25, 10, 16, 20, 7};
	int codgus;

	codgus = minimo(vec, ngus);

    cout << "Mínima cantidad: " << vec[codgus] << endl
         << "Índice: " << codgus << endl;

	return 0;
}

