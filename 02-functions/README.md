# [AED](https://github.com/rnsavinelli/aed) | Clase 02 - Funciones

Sobre funciones, pasaje por valor, pasaje por referencia, *scope* y
recursividad.

## Funciones

Una función es una secuencia de instrucciones con una finalidad en común
unificadas en una sentencia. La misma posee un valor de retorno, un nombre u
identificador, y, de necesitarse, parámetros de entrada.
Esto permite encapsular procedimientos o algoritmos.

Su definición en C/C++ tiene esta forma:

``` cpp
return-type function-ame(parameter declarations, if any)
{
    declarations
    statements
}
```

Un ejemplo de declaración sería:

``` cpp
int power(int base, int n);
```

Un ejemplo de implementación sería:

``` cpp
/* power: raise base ti n-th power; n >= 0 */
int power(int base, int n) {
    int p = 1;

    for (int i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

Si una función está correctamente diseñada es posible ignorar el cómo
realiza un trabajo/cómputo; con sólo saber qué hace debería ser suficiente,
permitiéndole al programador ocuparse sólo en su implementación y no de su
codificación.

**IMPORTANTE:** Antes de utilizar una función, al igual que con una variable, ésta
debe haber sido definida, o al menos declarada, con antelación.

Un ejemplo esquemático de su utilización sería:

``` cpp
#include <iostream>

using namespace std;

int power(int base, int n);

int main(void)
{
    int base = 0, exponent = 0;
    int output = 0;

    cout << "Enter a base: ";
    cin  >> base;

    do {
        cout << "Enter an exponent: ";
        cin  >> exponent;
    } while(exponent < 0);

    output = power(base, exponent);

    cout << "Result: " << output << endl;

    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int p = 1;

    for (int i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

```

## Parámetros

Denominándose parámetros formales a los explicitados en la definición de la
función, y parámetros reales a los utilizados al llamar a la función,
en C++ hay dos tipos de pasaje de parámetros: por valor y por referencia.

### Pasaje por valor

El parámetro formal recibe una copia del valor del parámetro
real. Esto permite que el parámetro real, además de una
variable, pueda ser una constante o una expresión. Las
modificaciones hechas al parámetro formal durante la ejecución
de la función no afectan al parámetro real.

### Pasaje por referencia

Requiere que el parámetro real sea una variable. El parámetro
formal pasa a ser un “alias” del parámetro real.
Durante la ejecución de la función los cambios realizados en el parámetro
formal se hacen **realmente** con el parámetro actual. Ergo, modificar
el valor de este “alias” modifica el valor de la variable original.

## Ámbito/Alcance

El ámbito, o *scope*, de un identificador es la porción de
código en la cuál está asociado a un determinado objeto
(variable, función, etc). Esto define su alcance, es decir, en
que partes del programa el identificador puede ser usado.

Las variables declaradas dentro de un bloque/función son por
defecto automáticas. Son creadas cuando el programa
ingresa en el bloque que las define y se destruyen al salir
del mismo. Al crear la variable su valor es indeterminado,
el programador debe asignar un valor explícitamente.

Las variables declaradas a nivel de archivo, denominadas globales, son
estáticas y existen durante toda la ejecución del programa. Si el
programador no las inicializa explícitamente son puestas
“a cero” antes de comenzar el mismo.

## Modificadores de *scope*

Las variables declaradas dentro de un bloque con clase de
almacenamiento *static* pasan a ser estáticas, como las
declaradas a nivel de archivo, y por tanto vale para ellas el lo
dicho en el punto anterior.

+ Existen durante toda la ejecución del programa.
+ Inicializadas en cero por defecto.

Para poder usar una variable declarada a nivel de archivo en un
fuente distinto a donde se la definió, se usa la clase de
almacenamiento *extern* para indicar que no se define una nueva
variable, sino que se quiere usar una ya definida en otro fuente.

Si una variable a nivel de archivo se la declara con clase de
almacenamiento *static*, entonces no es posible usarla desde otro
fuente, ni aún con *extern*. En este marco, la declaración de variables
globales en archivos de tipo *header* permite el uso de *extern* por
sobre *statics*.

## Recusividad

Denominase función recursiva a toda función que, en su código, se llama a si
misma una o más veces.

Es necesario tener un caso base, es decir, un caso que limite la recursión y
servirá al resto de los casos para construir la solución.

Los algoritmos recursivos suelen proveer soluciones elegantes y simples de entender, pero
no eficientes. Es por esto que se los suele convertir a una versión iterativa equivalente.

Ejemplo de implementación:

``` cpp
#include <iostream>

using namespace std;

int sigma(int n);

int main(int argc, char **argv)
{
	int x {0};

	cout << "This program adds the numbers from 1 to n." << endl;
	cout << "Enter a value for n: ";
	cin  >> x;

	cout << "Result: " << sigma(x) << endl;

	return 0;
}

int sigma(int n)
{
	return (n <= 0) ? 0 : n + sigma(n-1);
}
```

Alternativamente, la resolución de la función sigma de manera iterativa sería:

``` cpp
int sigma(int n)
{
    int sum {0};

    for (int i {1}; i <= n; i++) {
        sum += i;
    }

    return sum;
}
```

----------------------------------------------
La información contenida en estos documentos fue extraída de mis notas personales tomadas en UTN FRBA (Universidad Tecnológica Nacional, Facultad Regional de Buenos Aires) para (K1003) Algoritmos y Estructuras de Datas como se dictó en 2020 por el Lic. Eduardo Zúñiga, y hereda la licencia [BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) por haberse hecho uso de material, de su autoría, bajo la misma.

R. Nicolás Savinelli, 2020 
