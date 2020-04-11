# [AED](https://github.com/rnsavinelli/aed) | Clase 00 - Introducción

Sobre definiciones de algoritmo, dato, estructuras de datos, variables y
operadores en C++;

## Algoritmo

Un algoritmo es una secuencia de pasos lógicos que permiten solucionar un
problema. De manera ampliada se puede definir al algoritmo como un conjunto de
instrucciones o reglas definidas y no-ambiguas, ordenadas y finitas que permite,
típicamente, solucionar un problema, realizar un cómputo, procesar datos y
llevar a cabo otras tareas o actividades. [<sup>1</sup>](https://dle.rae.es/?w=algoritmo&origen=REDLE)

## Dato

Un dato es la unidad mínima que compone la información. Alternativamente, en
computación, al dato se lo conoce como la expresión general que describe las características de las entidades sobre las cuales opera un algoritmo.

**Tipo de Dato:** Un espacio en memorias con restricciones que define un conjunto de valores posibles y un conjunto de operaciones (para un objeto).

+ Enteros: char, int
+ Reales: float, double
+ Lógicos: bool
+ Vacío: void

Algunos modificadores utilizados en c++ son: const, unsigned, short, static, long.

**Objeto:** Zona de la memoria que contiene un valor de un tipo dado y que es
referenciable por un identificador.

**Valor:** Es un conjunto de bits en la memoria interpretados según un tipo
de dato.

**Variable:** Es un objeto al cual le es asignado un nombre para facilitar su
uso.

**Declaración:** Es una sentencia que da un nombre a un objeto.

**Definición:** Es una declaración que reserva memoria para un objeto.

``` cpp
/* tipo_dato nombre_variable; */
unsigned int masa, fuerza;
bool flag;

/* tipo_dato nombre_variable = valor_inicial; */
short int dato = 2;
char letra = 'A';

/* tipo_dato nombre_variable {valor_inicial}; */
/* Definición recomendada desde el standard c++11 */
int dato {0};
```

## Estructura de Datos

Por estructura de datos se entiende un formato de organización, gestión y
almacenamiento de datos que permiten un eficiente acceso y modificación de los
mismos.

## Operadores

A continuación se listan los operadores disponibles en C++, así como también en otros lenguajes derivados de la familia C.

### Aritmeticos

+ Suma, Resta: '+', '-'
+ Multiplicación, división:  '\*', '/'
+ Módulo: '%'

### De asignación

+ Asignar: '='
+ Asignar y sumar: '+='
+ Asignar y restar: '-='

Genéricamente, asignar y operar se puede escribir como 'X=', siendo 'X' el operador aritmético".

### Relacionales

+ Menor, mayor: '<', '>'
+ Menor o igual, mayor o igual: '<=', '>='
+ Igual, distinto: '==', '!='

### Lógicos

+ Negación: '!'
+ AND: '&&'
+ OR:  '||'

### De bits

+ AND: '&'
+ OR: '|'
+ XOR: '^'
+ Desplazamiento a derecha: '>>'
+ Desplazamiento a izquierda: '<<'
+ Complemento a uno: '~'

## Incremento y Decremento

Siendo estos operadores '++' y '--', su función se ve alterada según se aplique como pre-modificador o post-modificador (prefijo/sufijo).

### Como pre-modificador
``` cpp
/* Incremento, luego uso */
int x, y;

x = 0;
y = ++x; /* x = 1, y = 1*/
```

### Como post-modificador
``` cpp
/* Uso, luego incremento */
int x, y;

x = 0;
y = x++; /* x = 1, y = 0 */
```
