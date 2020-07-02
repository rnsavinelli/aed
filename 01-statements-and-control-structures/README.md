# [AED](https://rnsavinelli.github.io/files/notes/algorithms_and_data_structures/ads.html) | Clase 01 - Sentencias

Sobre sentencias simples y compuestas, estructuras de control, diagramas Nassi-Shneiderman.

## Sentencias

Las acciones a realizar por un programa son denominadas Sentencias. Ejemplos de Acciones frecuentes son: declarar una variable, asignar un valor, iterar por sobre un de bloque de código.

En C++ se denomina sentencia simple a una expresión singular seguida de un ';'. Ejemplos de esto son:

``` cpp
int x;
x = 0;
printf(...);
```

Por otro lado, en C++ se denomina sentencia compuesta a un bloque, o conjunto, de
sentencias simples encerradas dentro de un par de llaves {}. Un ejemplo de esto sería:

``` cpp
if (x != 0) {
    x = 0;
    i++;
}
```

## Estructuras de control

Existen tres estructuras de control, dentro de C/C++, para poder especificar el orden de
ejecución de nuestro código. Estas son:

Secuencial: Una cadena de sentencias operadas una después de la otra.

De selección: Dependiendo de el resultado de evaluar una condición, se ejecuta un grupo de sentencias u
otra.

De iteración: Se repite una o más sentencias de manera definida o indefinida a
partir de una condición final y/o inicial.

## De selección

### Sentencias if, if else, else y switch

Estas sentencias compuestas evalúan alguna condición y, en base al
resultado de la misma, ejecutan uno u otro bloque de código.

Estructura general de una sentencia *if*:

``` cpp
if (condition) {
    /* if true */
}
else {
    /* if false */
}
```

Nota: el *else* es de carácter omisible si no se ejecutarán sentencias
al llamarlo.

Siendo que el *else* se acopla al *if* más cercano el uso de llaves
generalmente simplifica la comprensión del programa. Esto indica que este
programa:

``` cpp
if (foo > 0) {
    if (foo > bar) {
        return 0;
    }
} else {
    return -1;
}
```

Es distinto de este otro:

``` cpp
if (foo > 0)
    if (foo > bar)
        return 0;
    else
        return -1;
```

El primero evalúa si foo es mayor que cero, si esto no se cumple devuelve -1, si se cumple evalúa si foo es mayor que bar, en cuyo caso devuelve 0.
El segundo evalúa si foo es mayor que cero, si esto no se cumple continua
ejecutando otro código, si esto se cumple y foo es mayor que bar devuelve cero, sino -1.

Por supuesto se pueden anidar/encadenar *if* - *else if* de modo tal de lograr
una selección entre varios casos. Esto es:

``` cpp
if (codition_a) {
    /* some statements */
} else if (condition_b) {
    /* some other statements */
} else {
    /* if not a, nor b, nor any defined condition
     * then execute some other statements
     */
}
```

Existe la sentencia compuesta switch que nos permite, de manera más clara
reescribir lo anterior como:

``` cpp
switch(condition) {
case a:
    /* some statements */
    break;
case b;
    /* some other statements */
    break;
default:
    /* if not a, nor b, nor any defined value for condition
     * then execute some other statements
     */
    break;
}
```

Nota: ante la ausencia del *break* continúa con la ejecución del código que le
sigue, **ignorando el case**, hasta encontrar un break;.

### Operador ? :

La semántica, por norma general, es:

``` cpp
condition ? if_true : if_false;
```

Este operador evalúa una condición y, según su resultado (true/false), realiza una
operación u otra.

## Iteración

### While

De forma cíclica itera **cero** o más veces por sobre una, o más, sentencias
mientras una condición sea verdadera.

``` cpp
while(condition) {
    /* some statements */
}
```

Ejemplo de uso:

``` cpp
while(foo > 0) {
    cout << foo << "is " << (foo%2 == 0 ? "even" : "odd") << endl;
    n--;
}
```

De forma cíclica iterar **una** o más veces mientras una condición sea verdadera:

``` cpp
do {
    /* some statements */
} while(condition);
```

### For

Comportándose de manera similar al *while* su forma general es:

``` cpp
for(initial_expression; condition; final_expression) {
    /* some statements */
}
```

Equivalente a:

``` cpp
initial_expression;
while(condition) {
    /* some statements */
    final_expression;
}
```

## Diagrama Nassi-Shneiderman

Para poder redactar algoritmos de manera abstraída e independiente de todo
lenguaje de programación utilizaremos los diagramas NSD (Nassi-Schneiderman
diagrams) que nos permiten, de manera gráfica, representar la estructura de
nuestro código.

### Secuencial

Utilizando bloques de proceso, que indican que la operación dentro de ellos
se debe realizar, podemos listar pasos a seguir por un programa:

![**Figura 1:** Bloque de Proceso](https://upload.wikimedia.org/wikipedia/commons/a/a2/Process_Block2.jpg)

Imagen extraída de Wikipedia.
Véase más en: [Diagrama Nassi Shneiderman](https://es.wikipedia.org/wiki/Diagrama_Nassi-Shneiderman)

### De Selección

Siendo el equivalente representativo del *if*, *if else*, *else*, se utilizan para
indicar una bifurcación en el código donde, al evaluarse una condición, se
ejecuta una rama u otra. De manera gráfica:

![**Figura 2:** Bloque de Bifurcación](https://upload.wikimedia.org/wikipedia/commons/7/79/Two-Way_Branch.jpg)

Imagen extraída de Wikipedia.
Véase más en: [Diagrama Nassi Shneiderman](https://es.wikipedia.org/wiki/Diagrama_Nassi-Shneiderman)

### De Iteración

Permitiéndonos representar sentencias del tipo *for*, *while* y *do while*, se
utilizan para indicar que un bloque de código deberá ejecutarse de manera
recursiva hasta satisfacer un condición establecida por el programador.

Evalúo la condición primero, luego ejecuto:

![**Figura 3:** Bloque de Iteración (for/while)](https://upload.wikimedia.org/wikipedia/commons/9/90/Test_First.jpg)

Imagen extraída de Wikipedia.
Véase más en: [Diagrama Nassi Shneiderman](https://es.wikipedia.org/wiki/Diagrama_Nassi-Shneiderman)

Ejecuto, luego evalúo la condición:

![**Figura 4:** Bloque de Iteración (do while)](https://upload.wikimedia.org/wikipedia/commons/b/be/Test_Last.jpg)

Imagen extraída de Wikipedia.
Véase más en: [Diagrama Nassi Shneiderman](https://es.wikipedia.org/wiki/Diagrama_Nassi-Shneiderman)

## Break y Continue

Utilizados para intervenir el orden de ejecución del código, son frecuentemente
usados dentro de ciclos iterativos.

La sentencia *break* provee una salida temprana a toda estructura de iteración
vista previamente. Siendo ésta una salida inmediata que finaliza el *loop*.

La sentencia *continue* provee un salto a la próxima iteración, ignorando el
código a posteriori para la presente ejecución, sin salirse del *loop*. Esto es,
llama a la siguiente evaluación de condición, omitiendo la presente.

----------------------------------------------
La información contenida en estos documentos fue extraída de mis notas personales tomadas en UTN FRBA (Universidad Tecnológica Nacional, Facultad Regional de Buenos Aires) para (K1003) Algoritmos y Estructuras de Datas como se dictó en 2020 por el Lic. Eduardo Zúñiga, y hereda la licencia [BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) por haberse hecho uso de material, de su autoría, bajo la misma.

R. Nicolás Savinelli, 2020
