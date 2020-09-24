// Roberto Nicolás Savinelli
// Legajo: 1645407

#include <iostream>
#include <fstream>

#define DATAFILE "Datos.txt"
#define ERROR -1

#define ULTIMODIGITOLEGAJO 7

using namespace std;

const int dim {7};

int leerarchivo(string file_name, int mat[][dim], int size)
{
    if(size != dim) {
        return ERROR;
    }

    ifstream file;

    file.open(file_name);

    if (!file.is_open()) {
        return ERROR;
    }

    int codigo, area, cantidad;
    while(file >> codigo >> area >> cantidad) {
        mat[codigo][area] += cantidad;
    }

    file.close();
    return 0;
}

void mat_print(int mat[][dim], int dim) {
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            cout << i << '\t' << j << '\t' << mat[i][j] << endl;
}

void puntouno(int v[], int dim) {
    for(int i = 0; i < dim; i++) {
        if(i == 0) {
            v[i] = 3;
        } else {
            v[i] = i * v[i-1];
            if(v[i] > 30) {
                v[i] %= 13;
            }
        }
    }
}

void vec_print(int v[], int dim) {
    for(int i = 0; i < dim; i++) {
        cout << i << ": " << v[i] << endl;
    }
}

void vec_print(float v[], int dim) {
    for(int i = 0; i < dim; i++) {
        cout << i << ": " << v[i] << endl;
    }
}

void puntodos(int mat[][dim], int index, float factor, float vec[]) {
    for(int i = 0; i < dim; i++) {
        vec[i] = mat[index][i] * factor;
    }
}

void puntotres(int vints[], float vfloats[], int var) {
    for(int i = 0; i < dim; i++) {
        if(var == 0) {
            vfloats[i] = 1;
        } else {
            vfloats[i] *= vints[i];
            vfloats[i] /= var;
        }
    }
}

void ordenarpar(float factores[], int ponderadores[], const int dim, int (*criterio)(int, int))
{
    int i = 1;

    while(i < dim) {
        int j = i;

        while(j > 0 && criterio(factores[j-1], factores[j]) > 0) {
            swap(factores[j], factores[j-1]);
            swap(ponderadores[j], ponderadores[j-1]);
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
    int mat[dim][dim] = {0};
	//punto a

    leerarchivo(DATAFILE, mat, dim);
    cout << "Matriz: " << endl;
    mat_print(mat, dim);

	//punto b
    int ponderadores[dim] = {0};

    puntouno(ponderadores, dim);
    cout << endl << "Vector de ponderadores: " << endl;
    vec_print(ponderadores, dim);

	//punto c
    float factores[dim] = {0.0};

    int indicemat = (ULTIMODIGITOLEGAJO % dim);
    int indicefac = ((dim - 1) - indicemat);

    cout << endl << "Vector de factores: " << endl;
    puntodos(mat, indicemat, ponderadores[indicefac], factores);
    vec_print(factores, dim);

	//punto d
    int divisor;

    //divisor = (indicemat > indicefac) ? indicemat - indicefac : indicefac - indicemat;
    if (indicemat > indicefac) {
        divisor = indicemat - indicefac;
    } else {
        divisor = indicefac - indicemat;
    }

    puntotres(ponderadores, factores, divisor);
    cout << endl << "Vector de factores procesados: " << endl;
    vec_print(factores, dim);

	//punto e
    ordenarpar(factores, ponderadores, dim, ascendente);
    cout << endl << "Ponderadores\tFactores" << endl;
    for(int i = 0; i < dim; i++) {
        cout << ponderadores[i] << "\t\t" << factores[i] << endl;
    }

	return 0;
}

