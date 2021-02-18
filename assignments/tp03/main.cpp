/* Roberto Nicolás Savinelli
 * LEGAJO: 1645407
 * */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "linkedlists/linkedlists.h"
#include "rwstring/rwstring.h"

#define DATA_FILE "data/Datos.bin"

#define PRODUCTO_SIZE 12
#define NOMBRE_SIZE 16
#define BANDERA_SIZE 10

using namespace std;

typedef struct cargamento
{
    string producto = "";
    int n_contenedores = 0;
} cargamento_t;

typedef struct buque
{
    string nombre = "";
    string bandera = "";
    int total_contenedores = 0;
    Node<cargamento_t> *cargamento = nullptr;
} buque_t;

typedef struct puerto
{
    int muelle = 0;
    int n_buques = 0;
    Node<buque_t> *buque = nullptr;
} puerto_t;

fstream &operator>>(fstream &fs, puerto_t &puerto)
{
    fs.read(reinterpret_cast<char *>(&puerto.muelle), sizeof(puerto.muelle));
    return fs;
}

fstream &operator>>(fstream &fs, buque_t &buque)
{
    buque.nombre = readstring(fs, NOMBRE_SIZE);
    buque.bandera = readstring(fs, BANDERA_SIZE);
    return fs;
}

fstream &operator>>(fstream &fs, cargamento_t &cargamento)
{
    cargamento.producto = readstring(fs, PRODUCTO_SIZE);
    fs.read(reinterpret_cast<char *>(&cargamento.n_contenedores), sizeof(cargamento.n_contenedores));
    return fs;
}

ostream &operator<<(ostream &os, const cargamento_t &cargamento)
{
    os << setfill(' ') << setw(7) << " + " << cargamento.n_contenedores;
    os << " contenedores por " << cargamento.producto << ".";
    return os;
}

ostream &operator<<(ostream &os, const buque_t &buque)
{
    os << setfill(' ') << setw(5) << " - "
       << "Buque: " << buque.nombre << " con bandera de ";
    os << buque.bandera << " y " << buque.total_contenedores << " contenedores." << endl;
    stackPrint(buque.cargamento);
    return os;
}

ostream &operator<<(ostream &os, const puerto_t &puerto)
{
    os << "Muelle: " << puerto.muelle << " (buques por amarrar: " << puerto.n_buques << ")" << endl;
    stackPrint(puerto.buque);
    return os;
}

int criteriaMuelles(puerto_t a, puerto_t b)
{
    return a.muelle - b.muelle;
}

int criteriaBanderaBuque(buque_t a, buque_t b)
{
    if (a.bandera == b.bandera)
    {
        if (a.nombre == b.nombre)
        {
            return 0;
        }
        return a.nombre > b.nombre ? 1 : -1;
    }
    return a.bandera > b.bandera ? 1 : -1;
}

int criteriaProductos(string a, string b) {
    return a.compare(b);
}

int criteriaBanderas(string a, string b) {
    return a.compare(b);
}

int readbin(string filename, Node<puerto_t> *&ps, Node<string> *&productos, Node<string> *&banderas)
{
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if (!file.is_open())
    {
        return -1;
    }

    puerto_t puerto = {0, 0, nullptr};
    buque_t buque = {"", "", 0, nullptr};
    cargamento_t cargamento = {"", 0};
    while (file >> puerto)
    {
        if (file >> cargamento)
        {
            if (file >> buque)
            {
                Node<puerto_t> *plocation = insert_unique(puerto, ps, criteriaMuelles);
                if (!linear_search(buque, plocation->data.buque, criteriaBanderaBuque))
                {
                    plocation->data.n_buques++;
                }
                Node<buque_t> *blocation = insert_unique(buque, plocation->data.buque, criteriaBanderaBuque);
                blocation->data.total_contenedores += cargamento.n_contenedores;
                append(blocation->data.cargamento, cargamento);

                insert_unique(cargamento.producto, productos, criteriaProductos);
                insert_unique(buque.bandera, banderas, criteriaBanderas);
            }
        }
    }

    file.close();
    return 0;
}

void destroy(Node<puerto_t> *&ps)
{
    while (!stackEmpty(ps))
    {
        while (!stackEmpty(ps->data.buque))
        {
            while (!stackEmpty(ps->data.buque->data.cargamento))
            {
                pop(ps->data.buque->data.cargamento);
            }
            pop(ps->data.buque);
        }
        pop(ps);
    }
}

int solve(Node<puerto_t> *puertos, string producto, string bandera) {
    int n_contenedores = 0;

    while(!stackEmpty(puertos)) {
        Node<buque_t> *buques = puertos->data.buque;
        while(!stackEmpty(buques)) {
            if(buques->data.bandera == bandera) {
                Node<cargamento_t> *cargamentos = buques->data.cargamento;
                while(!stackEmpty(cargamentos)) {
                    if(cargamentos->data.producto == producto) {
                        n_contenedores += cargamentos->data.n_contenedores;
                    }
                    cargamentos = cargamentos->next;
                }
            }
            buques = buques->next;
        }
        puertos = puertos->next;
    }

    return n_contenedores;
}

bool prompt(string &producto, string &bandera) {
    cout << endl << "Producto: ";
    if(cin >> producto) {
        cout << "Bandera: ";
        if(cin >> bandera) {
            return true;
        }
        return false;
    }
    return false;
}

int solve_for_all_cases(Node<puerto_t> *ps, Node<string>* productos, Node<string>* banderas) {
    while(!stackEmpty(productos)) {
        Node<string>* bc = banderas;
        while(!stackEmpty(bc)) {
            cout << productos->data << " " << bc->data << " "
                 << solve(ps, productos->data, bc->data) << endl;
            bc = bc->next;
        }
        productos = productos->next;
    }
    return 0;
}

int main(void)
{
    Node<puerto_t> *ps = nullptr;
    Node<string> *productos = nullptr;
    Node<string> *banderas = nullptr;

    readbin(DATA_FILE, ps, productos, banderas);

    // Listar todas las combinaciones.
    solve_for_all_cases(ps, productos, banderas);
    stackErase(productos);
    stackErase(banderas);

    // Preguntar por un producto y una bandera y mostrar el resultado.
    // [CTRL + D] o [CTRL + C] para cortar.
    string producto, bandera;
    while(prompt(producto, bandera)) {
        cout << "Total de contenedores: "<< solve(ps, producto, bandera) << endl;
    }

    destroy(ps);

    return 0;
}
