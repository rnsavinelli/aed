# [AED](https://rnsavinelli.github.io/files/notes/algorithms_and_data_structures/ads.html) | Unidad 05 - Punteros

Sobre punteros, memoria dinámica y su implementación y uso en C++.

## Definición de puntero

Un puntero es una referencia a una ubicación en memoria.
Por ende, una variable de tipo puntero es una variable que
almacena una dirección de memoria.

Los punteros, en C/C++ se declaran agregando un "\*" precediendo inmediatamente al tipo de dato que la dirección de memoria almacenará. Esto es:

```cpp
float *foo; /* pointer to long */
int *bar;   /* pointer to int */
char **ham; /* pointer to pointer to char */
```

Nótese que, al declarar el puntero, se indica el tipo de aquello a lo que
apunta, de modo que pueda "interpretarse" lo que se
encuentra en esa dirección al desreferenciarse.

Esta dirección de memoria puede ser una que almacene
una variable, la dirección de comienzo del código de una
función, o la dirección de otra dirección en caso de puntero
a putero.

## Cómo hacer uso del puntero

Para obtener el valor de la variable a la cuál
apunta una variable de tipo puntero usamos el
operador de desreferenciación <b>*</b>.

Como, por definición, el puntero almacena la dirección de un espacio de memoria,
podemos asignarle la dirección de un valor que ya conocemos utilizando
el operador & sobre una variable ya instanciada. Este operador **&**, que se lee como
**la dirección de**, nos da la dirección de memoria de una variable declarada.

Ejemplo de lo explicado anteriormente es:

```cpp
int n = 5;              /* an int variable */
int *p;                 /* a pointer to an int */
p = &n;                 /* p now points to n */

cout << (*p) << endl;   /* dereferencing p will result in
                         * this line printing '5' to std
                        */
```

Al definir un puntero, de cualquier tipo, el modo de decir que no apunta a
ningún lado es asignarle el puntero nulo denominado *nullptr*. Podría representar, o no,
el valor de la dirección de memoria 0, pero funcionará como 0 en todos los casos. De modo que:

```cpp
int *p = nullptr;
```

Inicia un puntero **p** que apunta a **NULL**. Esto el un análogo de inicializar variables
en 0, pero con espacios de memoria.

NOTA: Desreferenciar un puntero nulo no es buena práctica puesto que deviene a fallas durante la ejecución del programa.

## Memoria dinámica

### new

Para asignar dinámicamente la memoria (en tiempo de ejecución) en C++, se utiliza
el operador **new**[<sup>1</sup>](https://www.cplusplus.com/reference/new/operator%20new/)
 que aloja memoria del tamaño del tipo que le es indicado y devuelve el puntero
a la misma. De modo que:

```cpp
float *pfa = new float;
```

Aloja memoria para una variable de tipo *float*.

Para con arreglos, se añade el tamaño del mismo entre corchetes inmediatamente
después del tipo de dato. Esto es, usando el operador **new[]**[<sup>2</sup>](https://www.cplusplus.com/reference/new/operator%20new[]/):

```cpp
float *pfb = new float[32];
```

Como se ve en el código, en este ejemplo, se declara un puntero *pfb* al cual
se le asigna la dirección de comienzo de un bloque de memoria de *floats*
de largo 32.

### delete

Una vez que la memoria asignada con new ya no es
necesaria, se libera utilizando el operador **delete**[<sup>3</sup>](https://www.cplusplus.com/reference/new/operator%20delete/)
para unidades singulares de memoria y el operador **delete[]**[<sup>4</sup>](https://www.cplusplus.com/reference/new/operator%20delete[]/)
para vectores. Entonces, siguiendo la nomenclatura utilizada anteriormente:

```cpp
delete pfa;
```

Libera la memoria almacenada para el puntero *pfa*, y

```cpp
delete[] pfb;
```

Libera la memoria almacenada para el puntero *pfb*.


### Ejemplo comprensivo

Un ejemplo de su implementación para crear un vector limpio dinámico de *ints* sería:

```cpp
int *arrCreate(const int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        *(arr+i) = 0;
    return arr;
}

int main(void)
{
    const int arr_size = 10;
    int *arr = arrCreate(arr_size);

    /* some code */

    delete[] arr;
    return 0;
}
```

En este ejemplo se declara un puntero *arr* tal que apunte a la dirección
de un puntero nuevo, y de tamaño *arr_size* (inicializado con todos sus valores en cero).
Posteriormente, se continua con el código/se ejecuta alguna rutina y,
finalmente, se libera la memoria pedida antes de salir.

----------------------------------------------
La información contenida en estos documentos fue extraída de mis notas personales tomadas en UTN FRBA (Universidad Tecnológica Nacional, Facultad Regional de Buenos Aires) para (K1003) Algoritmos y Estructuras de Datas como se dictó en 2020 por el Lic. Eduardo Zúñiga, y hereda la licencia [BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) por haberse hecho uso de material, de su autoría, bajo la misma.

R. Nicolás Savinelli, 2020

