# [AED](https://github.com/rnsavinelli/aed) | Clase 04 - Arreglos

Sobre arreglos, matrices y su implementación en funciones.

## ¿Qué es un arreglo?

Un arreglo es un grupo de espacios de memoria identificados por un **mismo nombre**.
Estos espacios de memoria, además, están relacionados por tener el **mismo
tipo de dato** y estar **almacenados de manera secuencial**. Para referirnos a un
elemento en particular de un arreglo debemos especificar el nombre del arreglo
y su número de posición.

En C++ un arreglo se declara utilizando []:

```cpp
/* vector[4] es un vector de ints de 4 posiciones */
int vector[4];
```

Para inicializar un arreglo al momento de declararlo se puede proceder de
distintas formas:

```cpp
int v[5] {1, 6, 8, 3, 9};
int w[] {3, 12, 7};
int x[10] {0};
int z[10] {};
```

Nótese que en el caso de *w* no se indicó el tamaño
explícitamente, pero al iniciarlo con 3 elementos el
compilador lo genera de ese tamaño.

También podemos indicar el tamaño e inicializar una
cantidad de valores menor al tamaño, en cuyo caso los
valores no inicializados explícitamente, se inicializan,
implícitamente, en cero. Por ejemplo, el vector x tendrá sus
10 elementos inicializados en cero más allá de no haber sido
explicitado para todos y cada uno de sus elementos.
Lo mismo ocurre con z.

Para acceder al un elemento *n* lo podemos realizar de dos maneras distintas.
Ambas se ilustran en el siguiente ejemplo:

```cpp
/* En esta porción de código se accede a la posición 1 del arreglo `vector`,
/* y se le asigna el valor 0 de dos maneras equivalentes pero distintas. */

int foo[5];   /* Declaro un vector de ints de 5 posiciones */

foo[1] = 0;   /* La manera tradicional sería acceder de este modo para
              /* asignarle el valor 0 al elemento 1 */

*(foo+1) = 0; /* Alternativamente se puede acceder a el contenido
              /* de la dirección del elemento 0 más 1.
              /* Esto es posible puesto que todos los elementos son
              /* contiguos en la memoria y del mismo tipo. */
```

Un ejemplo básico y bastante comprensivo sería:

```cpp
#include <iostream>
#define SIZE 4

using namespace std;

int main(void)
{
    int arr[SIZE] {};

    cout << "An array of " << SIZE << " integers named \"arr\" was declared."
         << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value " << (i+1) << " of " << SIZE << ": ";
        cin >> arr[i];
    }

    cout << endl << "Data was stored as follows:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    return 0;
}
```

En este ejemplo se inicializa en cero un arreglo de *SIZE* posiciones (en este
caso 4) y, luego, se le pide al usuario ingrese los valores.
Posteriormente se imprime por pantalla cada elemento en el orden en el que se almacenó.

## Arreglos y Funciones

Los arreglos pueden pasarse como parámetros a
funciones, pero tienen particularidades con respecto
a otros tipos de variables:

- C/C++ pasa automáticamente por referencia los arreglos.
- El nombre del arreglo evalúa solamente la ubicación del primer elemento.

Consecuencia de esto es que:

- Cuando una función modifica el valor de un elemento de un arreglo modifica el valor real del mismo.
- La función que recibe el arreglo desconoce su dimensión. Es necesario pasar un parámetro adicional para informarla.

Ejemplo:

```cpp
#include <iostream>
#define SIZE 5

using namespace std;

/* doubles the value of every element in the array */
void double_all_elements(int arr[], const int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;
    }
}

int main(void)
{
    int arr[SIZE] {};

    cout << "An array of " << SIZE << " integers named \"arr\" was declared."
         << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value " << (i+1) << " of " << SIZE << ": ";
        cin >> arr[i];
    }

    cout << endl << "Data was stored as follows:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    double_all_elements(arr, SIZE);
    cout << endl << "Data after doubling all stored values:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    return 0;
}
```

## Matrices/Tablas

Los arreglos en C/C++ pueden tener múltiples subíndices (múltiples []).
Esto es, se puede definir un arreglo de arreglos.

Ejemplo de su declaración sería:

```cpp
int foo[2][4][3];
```

Este ejemplo define una matriz de ints de tres dimensiones, y:

```cpp
int bar[3][5];
```

Define un matriz de ints de dos dimensiones.

Un uso común de matrices con múltiples dimensiones es representar tablas.
Para identificar un elemento de la matriz, o tabla, en particular, debemos especificar
el valor de subíndice para cada [].

En tablas de 2 dimensiones, como el arreglo *bar* en el ejemplo, el primero
subíndice (por convención) indica la fila, y el segundo columna.

Ejemplo sencillo de su implementación:

```cpp
#include <iostream>

#define ROWS 3
#define COLS 4

using namespace std;

int main()
{
    int mat[ROWS][COLS];

    cout << "A matrix of integers with " << ROWS << " rows and " << COLS
         << " columns named \"mat\" was declared.";
    cout << endl << "Initializing values as mat[i][j] = i + j"
         << endl << endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat[i][j] = i + j;
        }
    }

    cout << "Printing all stored values: ";
    for (int i = 0; i < ROWS; i++) {
        cout << endl;
        for (int j = 0; j < COLS; j++) {
            cout << "mat[" << i << "][" << j << "] = " << mat[i][j] << endl;
        }
    }

    return 0;
}
```

## Matrices y Funciones

Idem [Arreglos y Funciones](#arreglos-y-funciones) con una salvedad. Como
la función que recibe a la matriz desconoce la dimensión de las columnas, debemos
explicitarlo. Esto le permite al compilador saber dónde comienza la fila siguiente.

Ejemplo:

```cpp

#include <iostream>

#define ROWS 3
#define COLS 4

using namespace std;

void matrix_clear(int m[][COLS], const int rows)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            m[i][j] = 0;
        }
    }
}

void matrix_print(int m[][COLS], const int rows)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "m[" << i << "][" << j << "] = " << m[i][j] << endl;
        }
        if (i != rows - 1) cout << endl;
    }
}

int main(void)
{
    int m[ROWS][COLS];
    cout << "A matrix of integers with " << ROWS << " rows and " << COLS
         << " columns named \"m\" was declared." << endl;

    cout << "Setting all values to zero..." << endl;
    matrix_clear(m, ROWS);
    cout << "Printing matrix:" << endl;
    matrix_print(m, ROWS);

    return 0;
}
```

En este ejemplo se declara una matriz *m* de *ROWS* filas y *COLS* columnas,
luego se limpian todos los valores no inicializados poniéndolos en cero y,
finalmente, se imprimen utilizando funciones invocadas en el main.
