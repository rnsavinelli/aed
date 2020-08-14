#include <iostream>

using namespace std;

const int nsuc = 8;
const int ngus = 6;

string vnomgus[ngus] {"Muzzarella", "Fugazza", "Anchoas", "Fugazzeta"
			, "Pizzaiola", "Jamón y Morrones"};

void
ordenarpar(int vcant[], string vnomgus[], const int ngus, int (*criterio)(int, int))
{
    int i = 1;

    while(i < ngus) {
        int j = i;

        while(j > 0 && criterio(vcant[j-1], vcant[j]) > 0) {
            swap(vcant[j], vcant[j-1]);
            swap(vnomgus[j], vnomgus[j-1]);
            j--;
        }
        i++;
    }
}

int
descendente(int a, int b)
{
	return b - a;
}

int
main(void)
{
	int vcant[ngus] {10, 25, 27, 42, 40, 26};

	ordenarpar(vcant, vnomgus, ngus, descendente);

    cout << "Gusto -> Cantidad" << endl;
    for(int i = 0; i < ngus; i++) {
        cout << vnomgus[i] << " -> " << vcant[i] << endl;
    }

	return 0;
}
