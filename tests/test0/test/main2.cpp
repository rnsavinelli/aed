// Roberto Nicolás Savinelli
// Legajo: 1645407

#include <iostream>

using namespace std;

const int dim {7};

void puntodos(int mat[][dim], int index, float factor, float vec[]) {
    for(int i = 0; i < dim; i++) {
        vec[i] = mat[index][i] * factor;
    }
}

void vec_print(float v[], int dim) {
    for(int i = 0; i < dim; i++) {
        cout << i << ": " << v[i] << endl;
    }
}

int main()
{
	int mat[dim][dim] {
	 3, 87, 11, 45,  4, 98,  62,
	33, 46, 41, 24,  5, 35,  43,
	59,  5, 48, 70, 37,  0,  25,
	27, 59, 14, 44, 13, 31,  71,
	28, 42, 12,  7, 34, 58, 123,
	49, 19, 40, 13, 27, 82,  68,
	31, 29, 66, 26, 21,  9,  29
	};
	float vec[dim];
	float factor1 {2.5};
	float factor2 {1.0};
	int indice {2};
	//Aqui llamar a la función y mostrar el resultado, para los dos factores con el mismo indice

    cout << "Factor = " << factor1 << ":" << endl;
    puntodos(mat, indice, factor1, vec);
    vec_print(vec, dim);

    cout << endl << "Factor = " << factor2 << ":" << endl;
    puntodos(mat, indice, factor2, vec);
    vec_print(vec, dim);

	//debería dar algo como
	/*
	0: 147.5
	1: 12.5
	2: 120
	3: 175
	4: 92.5
	5: 0
	6: 62.5
	================
	0: 59
	1: 5
	2: 48
	3: 70
	4: 37
	5: 0
	6: 25
	*/
	return 0;
}

