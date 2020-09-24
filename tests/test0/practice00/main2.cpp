#include <iostream>

using namespace std;

const int nsuc = 8;
const int ngus = 6;

//Aqui programe la funcion minimo
int minimo(int v[], const int size)
{
    int min = v[0];
    int min_i = 0;

    for(int i = 1; i < size; i++) {
        if (v[i] <= min) {
            min = v[i];
            min_i = i;
        }
    }

    return min_i;
}

int main()
{
	int vec[ngus] {38, 25, 10, 16, 20, 7};
	int codgus;

	codgus = minimo(vec, ngus);

    cout << "Mínima cantidad = " << vec[codgus] << ", en el índice "
         << codgus << "." << endl;

	return 0;
}
