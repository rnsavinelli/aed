#include <iostream>
#include <fstream>

#define DATA_FILE "Datos.txt"

#define ERROR -1

const int nsuc = 8;
const int ngus = 6;

using namespace std;

string vnomsuc[nsuc] {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete"
			, "ocho"};
string vnomgus[ngus] {"Muzzarella", "Fugazza", "Anchoas", "Fugazzeta"
			, "Pizzaiola", "Jamón y Morrones"};

void mayor(int mcantpizzas[][ngus], const int nsuc, int &isucmax, int &igusmax)
{
    int max = mcantpizzas[0][0];
    isucmax = 0;
    igusmax = 0;

    for(int i = 0; i < nsuc; i++) {
        for(int j = 0; j < ngus; j++) {
            if (mcantpizzas[i][j] > max) {
                max = mcantpizzas[i][j];
                isucmax = i;
                igusmax = j;
            }
        }
    }
}

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

int ascendente(int a, int b)
{
	return a - b;
}

int main(void)
{
	int mcantpizzas[nsuc][ngus] {0};

	//punto 1
    ifstream file;

    file.open(DATA_FILE);

    if(!file.is_open()) {
        return ERROR;
    }

    do {
        int sucursal, gusto, pizzas;
        file >> sucursal;
        file >> gusto;
        file >> pizzas;
        mcantpizzas[sucursal][gusto] += pizzas;
    } while(!file.eof());

    file.close();

	//punto 2
	//La mayor cantidad de pizzas se pidió en la sucursal cinco del gusto Fugazzeta
    int isucmax, igusmax;
    mayor(mcantpizzas, nsuc, isucmax, igusmax);
    cout << "Combinación sucursal-gusto vendió la mayor cantidad de pizzas:"
         << endl << "Sucursal: " << vnomsuc[isucmax]
         << endl << "Gusto: " << vnomgus[igusmax]
         << endl;

	//punto3
	//Mínima cantidad de pizzas vendidas en sucursal seis: 5 correspondiente al gusto Jamón y Morrones
    int isucsig = (isucmax + 1) % nsuc;
	int codgus;

	codgus = minimo(mcantpizzas[isucsig], ngus);

    cout << endl << "Sucursal: " << vnomsuc[isucsig] << endl
         << "Mínima cantidad = " << mcantpizzas[isucsig][codgus] << endl
         << "Gusto: " << vnomgus[codgus] << "." << endl;

	//punto4
	ordenarpar(mcantpizzas[isucmax], vnomgus, ngus, ascendente);

    cout << endl << "Gusto -> Cantidad" << endl;

    for(int i = 0; i < ngus; i++) {
        cout << vnomgus[i] << " -> " << mcantpizzas[isucmax][i] << endl;
    }
	/*
	Gusto		Cantidad
	Muzzarella	10
	Fugazza		25
	Jamón y Morrones26
	Anchoas		27
	Pizzaiola	40
	Fugazzeta	42
	*/
	return 0;
}

