# [AED](https://github.com/rnsavinelli/aed) | Clase 05 - Búsqueda Binaria

Sobre árboles binarios, su implementación, y el algoritmo de búsqueda binaria.

## Árbol Binario

Un árbol binario, para su uso en ciencias de la computación, es una estructura de datos compuesta de nodos con una variable denominada *llave* y un máximo de
*dos hijos* (ergo de su naturaleza binaria). Por otro lado, y citando la
definición teórica[<sup>1</sup>](https://es.wikipedia.org/wiki/%C3%81rbol_binario#Definici%C3%B3n_de_teor%C3%ADa_de_grafos), un árbol binario es un grafo conexo, acíclico y no dirigido tal que el grado de cada vértice no es mayor a 2.

![Grafo de un árbol binario de tamaño 9, alto 3 y raíz con valor igual a  2](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/192px-Binary_tree.svg.png)

Por norma general, cada hijo es un puntero y se los denomina hijo izquierdo y derecho. En C/C++ un árbol binario suele declararse de la siguiente manera:

```
struct node {
    int key;
    structnode *left;   /* left child */
    structnode *right;  /* right child */
};
```

Alternativamente, se lo puede declarar como un arreglo de punteros donde el
número de hijos, normalmente igual a dos, es variable. Este enfoque permite, además, el recorrido recursivo de tódos los hijos de un nodo.

```
#define NUM_CHILDREN (2)

structnode {
    int key;
    structnode *child[NUM_CHILDREN];
};
```

En lo respectivo a cuál enfoque es mejor utilizar depende sólamente de las preferencias del/los usuarios.

Si todos los hijos de un nodo almacenan alguna referencia, se dice que está
completo. Todo nodo con exactamente dos hijos es denominado *nodo interno*.

Si algún hijo de un nodo tiene como referencia a NULL, se lo denomina *nodo externo*.

## Búsqueda Binaria

