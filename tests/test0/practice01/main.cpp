#include <iostream>
#include <fstream>

#define DATA_FILE "Datos.txt"
#define ERROR -1

using namespace std;

const int nsuc = 8;
const int ngus = 6;

string vnomsuc[nsuc] {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete"
			, "ocho"};
string vnomgus[ngus] {"Muzzarella", "Fugazza", "Anchoas", "Fugazzeta"
			, "Pizzaiola", "Jamón y Morrones"};

int
readfile(string file_name, int data[][ngus], int nsuc)
{
    ifstream file;

    file.open(file_name);

    if (!file.is_open()) {
        return ERROR;
    }

    int sucursal, gusto, cant;

    while (!file.eof()) {
        file >> sucursal;
        file >> gusto;
        file >> cant;

        data[sucursal][gusto] += cant;
    }

    file.close();
    return 0;
}

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
ascendente(int a, int b)
{
	return a - b;
}

int main()
{
    int mcantpizzas[nsuc][ngus] = {0};

	// Punto 1
    if(readfile(DATA_FILE, mcantpizzas, nsuc)) {
        cout << "Error en la lectura del archivo " << DATA_FILE << "." << endl;
        return ERROR;
    }

	// Punto 2
	int isucmax, igusmax;

    mayor(mcantpizzas, nsuc, isucmax, igusmax);

    cout << "Combinación sucursal-gusto que vendió la mayor cantidad de pizzas:" << endl
         << "Sucursal: " << vnomsuc[isucmax] << endl
         << "Gusto: " << vnomgus[igusmax] << endl;

    // Punto3
    int isucsig = (isucmax + 1) % nsuc;

    int min_i = minimo(mcantpizzas[isucsig], ngus);

    cout << endl;
    cout << "Minima cantidad de pizzas: " << endl
         << "Sucursal: " << vnomsuc[isucsig] << endl
         << "Cantidad: " << mcantpizzas[isucsig][min_i] << endl
         << "Gusto: " << vnomgus[min_i] << endl;

	// Punto4
	ordenarpar(mcantpizzas[isucmax], vnomgus, ngus, ascendente);

    cout << endl;
    cout << "Gusto -> Cantidad" << endl;
    for(int i = 0; i < ngus; i++) {
        cout << vnomgus[i] << " -> " << mcantpizzas[isucmax][i] << endl;
    }

	return 0;
}

