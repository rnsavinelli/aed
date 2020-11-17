// Roberto Nicolás Savinelli
// Legajo: 1645407

#include <iostream>

using namespace std;

const int dim {7};

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

void vec_print(float v[], int dim) {
    for(int i = 0; i < dim; i++) {
        cout << i << ": " << v[i] << endl;
    }
}

int main()
{
	int vint[dim] {5, 6, 8, 11, 15, 20, 8};
	float vfloat[dim] {147.5, 12.5, 120, 175, 92.5, 0, 62.5};
	int entero {11};
	////Aqui llamar a la función y mostrar el resultado con las variables definidas arriba

    puntotres(vint, vfloat, entero);

    vec_print(vfloat, dim);
	//debería dar algo como
	/*
	0: 67.0455
	1: 6.81818
	2: 87.2727
	3: 175
	4: 126.136
	5: 0
	6: 45.4545
	*/
	return 0;
}

