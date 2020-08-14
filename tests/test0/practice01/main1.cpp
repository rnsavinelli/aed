#include <iostream>

using namespace std;

const int nsuc = 8;
const int ngus = 6;

void
mayor(int mcantpizzas[][ngus], const int nsuc, int &isucmax, int &igusmax)
{
    int maxpizzas = mcantpizzas[0][0];
    int newpizzas;
    isucmax = 0;
    igusmax = 0;

    for (int i = 0; i < nsuc; i++) {
        for (int j = 0; j < ngus; j++) {
            newpizzas = mcantpizzas[i][j];
            if (maxpizzas < newpizzas) {
                maxpizzas = newpizzas;
                isucmax = i;
                igusmax = j;
            }
        }
    }
}

int
main(void)
{
	int mcantpizzas[nsuc][ngus] {
	11, 25, 37,  7, 10, 32,
	28, 28, 12, 34,  0, 16,
	15, 12, 24,  2, 27, 20,
	 3, 13, 34, 16,  0, 36,
	10, 25, 27, 42, 40, 26,
	38, 25, 10, 16, 20,  5,
	27,  2,  9, 10,  3, 14,
	41, 19, 13, 23, 19, 25
	};
	int isucmax, igusmax;

    mayor(mcantpizzas, nsuc, isucmax, igusmax);

    cout << "Combinación sucursal-gusto que vendió la mayor cantidad de pizzas:" << endl
         << "Sucursal: " << isucmax  << endl
         << "Gusto: " << igusmax << endl;

	return 0;
}

