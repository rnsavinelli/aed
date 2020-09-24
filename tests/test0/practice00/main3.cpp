#include <iostream>

using namespace std;

const int nsuc = 8;
const int ngus = 6;

string vnomgus[ngus] {"Muzzarella", "Fugazza", "Anchoas", "Fugazzeta"
			, "Pizzaiola", "Jamón y Morrones"};

void ordenarpar(int vec_a[], string vec_b[], int dim, int (*criterio)(int, int))
{
    int i = 1;

    while(i < dim) {
        int j = i;

        while(j > 0 && criterio(vec_a[j-1], vec_a[j]) > 0) {
            swap(vec_a[j], vec_a[j-1]);
            swap(vec_b[j], vec_b[j-1]);
            j--;
        }
        i++;
    }
}

int descendente(int a, int b)
{
	return b - a;
}

int main()
{
	int vcant[ngus] {10, 25, 27, 42, 40, 26};

	ordenarpar(vcant, vnomgus, ngus, descendente);

    for(int i = 0; i < ngus; i++) {
        cout << vcant[i] << " -> " << vnomgus[i] << endl;
    }

	return 0;
}

