# [AED](https://github.com/rnsavinelli/aed) | Búsqueda Binaria

Sobre árboles binarios, su implementación en C/C++, y el algoritmo de búsqueda binaria.

## Árbol Binario

Un árbol binario, para su uso en ciencias de la computación, es una estructura de datos compuesta de nodos con una variable denominada **clave** y un máximo de
**dos hijos** (ergo de su naturaleza binaria). Por otro lado, y citando la
definición teórica[<sup>1</sup>](https://es.wikipedia.org/wiki/%C3%81rbol_binario#Definici%C3%B3n_de_teor%C3%ADa_de_grafos), un árbol binario es un grafo conexo, acíclico y no dirigido tal que el grado de cada vértice no es mayor a 2.

![Grafo de un árbol binario de tamaño 9, alto 3 y raíz con valor igual a  2](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/192px-Binary_tree.svg.png)

Por definición, cada hijo es un puntero y se los denomina hijo izquierdo y derecho. En C/C++ un árbol binario suele declararse de la siguiente manera:

```cpp
struct node {
    int key;
    struct node *left;   /* left child */
    struct node *right;  /* right child */
};
```

Alternativamente, se lo puede declarar como un arreglo de punteros donde el
número de hijos, normalmente igual a dos, es variable. Este enfoque permite, además, el recorrido recursivo de tódos los hijos de un nodo.

```cpp
#define NUM_CHILDREN (2)

structnode {
    int key;
    struct node *child[NUM_CHILDREN];
};
```

En lo respectivo a cuál enfoque es mejor utilizar depende sólamente de las preferencias del/los usuarios.

Si todos los hijos de un nodo almacenan alguna referencia, se dice que está
**completo**. Todo nodo con exactamente dos hijos es denominado **nodo interno**.

Si algún hijo de un nodo tiene como referencia a `NULL`, se lo denomina **nodo externo**.

## Búsqueda Binaria

Un árbol de búsqueda binaria es un árbol binario en el que cada nodo tiene
una clave tal que, la misma, es mayor que todas las claves en el subárbol de su hijo izquierdo y menor que todas las claves en el subárbol de su hijo derecho. Esto permite buscar un nodo utilizando el enfoque de dividir y conquistar:

```cpp
structnode *
treeSearch(struct node *root, int target)
{
    while(root != 0 && root->key != target) {
        if(root->key > target) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}
```

Su aplicación para con vectores, en vez de nodos, sería:

Comparar la clave buscada contra el elemento del medio del vector. Si son iguales, entonces, ya se encontró el elemento y la búsqueda finaliza. Si la clave es menor que el
elemento del medio, se descarta la mitad superior del vector. En modo similar, si es mayor, la parte inferior se descarta.

```cpp
#define NOT_FOUND (-1)

int
treeSearch(int key, int arr[], int size)
{
	int low = 0;
	int high = size - 1;

	while (low <= high) {
        	/* https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html */
		mid = inf + ((high - low) / 2);

		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			high = mid - 1;
		else /* (arr[mid] < clave) */
			low = mid + 1;
	}

	return NOT_FOUND;
}
```
