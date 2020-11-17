// Roberto Nicolás Savinelli
// Legajo: 1645407

#include <iostream>

using namespace std;

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

int main()
{
	const int dim1 {7};
	const int dim2 {15};
	int v1[dim1], v2[dim2];
	//Aqui llamar a la función y mostrar el resultado, para los dos vectores

    cout << "Primer vector:" << endl;
    puntouno(v1, dim1);
    vec_print(v1, dim1);

    cout << endl << "Segundo vector:" << endl;
    puntouno(v2, dim2);
    vec_print(v2, dim2);

	//debería dar algo como
	/*
	0: 3
	1: 3
	2: 6
	3: 18
	4: 7
	5: 9
	6: 2
	================
	0: 3
	1: 3
	2: 6
	3: 18
	4: 7
	5: 9
	6: 2
	7: 14
	8: 8
	9: 7
	10: 5
	11: 3
	12: 10
	13: 0
	14: 0
	*/
	return 0;
}

