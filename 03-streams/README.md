# [AED](https://github.com/rnsavinelli/aed) | Clase 03 - Flujos

Sobre flujos de lectura, escritura y posicionamiento implementando `<fstream>` en
C++.

## ¿Qué es un flujo?

El término flujo es una abstracción conceptual que modeliza una cola de
datos lineal que conecta un archivo, o fuente, con un programa,
y que facilita el intercambio de datos entre los mismos.

## Flujos predefinidos <iostream>

El flujo estándar de *input* que utilizamos al desarrollar en C++ es el
objeto de tipo `istream` denominado `std::cin`<sup>[1](https://www.cplusplus.com/reference/iostream/cin/)</sup>.
Su implementación, de manera genérica, sigue el siguiente formato:

``` cpp
int foo;
std::cin >> foo;
```

En este ejemplo, se declara una variable de tipo `int` denominada 'foo' y, luego, se extrae del
*stream*, o flujo, `cin` el valor a almacenar.

El flujo estándar de *output* que utilizamos al desarrollar en C++ es el objeto de
tipo `ostream` denominado `std::cout`<sup>[2](https://www.cplusplus.com/reference/iostream/cout/)</sup>.
Su implementación, de manera genérica, sigue el siguiente formato:

``` cpp
int var = 5;
std::cout << "var == " << var << std::endl;
```

En este ejemplo, se declara una variable de tipo `int` denominada 'var' y,
luego, se insertan la cadena de caracteres "var == ", el valor de la variable 'var', y
un `endl`, en el *steam* `cout`. `std::endl` se utiliza para insertar un
carácter de nueva linea y realizar un *flush* del *buffer* asociado
<sup>[3](https://www.cplusplus.com/reference/ostream/endl/)</sup>, lo que
implica sincronizar, este último, con su sequencia de control. En otras
palabras, como se utilizan buffers intermediarios en la implementación de los
streams, se solicita se escriba el contenido del buffer en la secuencia de control.

Otros steams útiles y que están definidos en `<iostream>` son `std::cerr`
<sup>[4](https://www.cplusplus.com/reference/iostream/cerr/)</sup> y
`std::clog`<sup>[5](https://www.cplusplus.com/reference/iostream/clog/)</sup>,
que se utilizan como *standard error* y *standard logging* respectivamente.

## Flujos con archivos <fstream>

Similar, en su operatoria, a los flujos predefinidos se utilizan para la
lectura y escritura por medio de archivos. Esto permite leer un *input* de
datos, o escribir un *output* de datos por sobre otros medios que no sean
los definidos por defecto.

La operatoria con archivos sigue la siguiente metodología:

+ Definir el *stream* (ofstream/ifstream/fstream).
+ Abrir, o vincular, el archivo definiendo su modo de operación lectura y/o escritura.
+ Manipular/utilizar los datos.
+ Cerrar/liberar el archivo.

### Ejemplo de solo escritura

``` cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;
    int foo = 0;

    file.open("file.txt");
    if (!file.is_open()) {
        cout << "ERROR: Failed to open the file!" << endl;
        return -1;
    }

    file << "Inputting some text" << endl;
    file << "Text plus a variable " << foo << endl;
    file.close();
    return 0;
}
```

### Ejemplo de solo lectura

``` cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    string input;

    file.open("file.txt");
    if (!file.is_open()) {
        cout << "ERROR: File not found!" << endl;
        return -1;
    }

    file >> input;
    cout << input << endl;

    file.close();

    return 0;
}
```

### Ejemplo de lectura y escritura

``` cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    string data_read;

    file.open("file.txt");
    if (!file.is_open()) {
        cout << "ERROR: Failed to open the file!" << endl;
        return -1;
    }

    file << "Lorem ipsum dolor sit amet" << endl;

    file.seekg(0, ios::beg); /* resets position pointer so that it
                                points to the beggining of the file */

    file >> data_read;
    cout << "Read: " << data_read << endl;
    file.close();

    return 0;
}
```

## Posicionamiento

Las funciones de posicionamiento que provee `<fstream>` nos permiten conocer y modificar
cuál es la ubicación de los punteros de un *stream*. Estos punteros son:
uno de lectura denominado **g** (*get*), y uno de escritura denominado **p** (*put*).
Es habitual que si el flujo es un archivo, se use un único puntero para ambos casos.

### tellg();<sup>[6](https://www.cplusplus.com/reference/istream/istream/tellg/)</sup>

`tellg();` devuelve el valor del puntero de posición en el *input stream*.

Sea `file` una variable de tipo `fstream`, se presenta un ejemplo de
implementación de la función para conocer la ubicación del puntero de lectura:

``` cpp
streampos inputpos;
inputpos = file.tellg();
```

### seekg();<sup>[7](https://www.cplusplus.com/reference/istream/istream/seekg/)</sup>

`seekg();` modifica el valor del puntero de posición en el *input stream*.

Definida como:

```
(1)	istream& seekg (streampos pos);
(2)	istream& seekg (streamoff off, ios_base::seekdir way);
```

Donde `pos` es la posición del puntero **g**, `off` es el *offset* relativo al
parámetro `way`, y `way` es la dirección en la que se efectúa la busqueda.

Los posibles valores de `way` son:

| value | offset is relative to... |
| :---: | :----------------------: |
|ios_base::beg | beginning of the stream |
|ios_base::cur | current position in the stream |
|ios_base::end | end of the stream |

### tellp();<sup>[8](https://www.cplusplus.com/reference/ostream/ostream/tellp/)</sup>

`tellp();` devuelve el valor del puntero de posición en el *output stream*.

Sea `file` una variable de tipo `fstream`, se presenta un ejemplo de
implementación de la función para conocer la ubicación del puntero de escritura:

``` cpp
streampos outputpos;
outputpos = file.tellp();
```

### seekp();<sup>[9](https://www.cplusplus.com/reference/ostream/ostream/seekp/)</sup>

`seekp();` modifica el valor del puntero de posición en el *output stream*.

Definida como:

```
(1)	ostream& seekp (streampos pos);
(2)	ostream& seekp (streamoff off, ios_base::seekdir way);
```

Donde `pos` es la posición del puntero **p**, `off` es el *offset* relativo al
parámetro `way`, y `way` es la dirección en la que se efectúa la busqueda.

Los posibles valores de `way` son:

| value | offset is relative to... |
| :---: | :----------------------: |
|ios_base::beg | beginning of the stream |
|ios_base::cur | current position in the stream |
|ios_base::end | end of the stream |
