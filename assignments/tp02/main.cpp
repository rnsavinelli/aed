#include <iostream>
#include <fstream>
#include <iomanip>

#include "linkedlists/linkedLists.h"
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

int readbin(string filename, Node<puerto_t> *&ps)
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

void first_prompt(Node<puerto_t> *&ps)
{
    puerto_t tmp;

    cout << "Ingrese muelle a buscar: ";

    while (cin >> tmp.muelle)
    {
        if (tmp.muelle == -1) {
            cout << endl;
            return;
        }
        Node<puerto_t> *ptr = search(tmp, ps, criteriaMuelles);
        if (!stackEmpty(ptr))
        {
            cout << ptr->data << endl;
        }
        else
        {
            cout << "Muelle no encontrado." << endl;
        }
        cout << setfill('#') << setw(80) << "#" << endl;
        cout << "Ingrese muelle a buscar: ";
    }
}

void second_prompt(Node<puerto_t> *&ps)
{
    puerto_t origen;
    puerto_t destino;
    buque_t buqueAux;

    append(origen.buque, buqueAux);

    cout << "DATOS PARA MOVER UN REGISTRO: " << endl;

    cout << "Ingrese el muelle de origen: ";
    cin >> origen.muelle;
    cin.clear();
    cin.ignore();

    cout << "Ingrese un buque: ";
    getline(cin, buqueAux.nombre);

    cout << "Ingrese la bandera de dicho buque: ";
    getline(cin, buqueAux.bandera);

    append(origen.buque, buqueAux);

    cout << "Ingrese el muelle de destino: ";
    cin >> destino.muelle;
    cin.ignore();

    Node<puerto_t> *ptrorigen = search(origen, ps, criteriaMuelles);
    if (!stackEmpty(ptrorigen))
    {
        Node<buque_t> *ptrbuque = extract(buqueAux, ptrorigen->data.buque, criteriaBanderaBuque);
        if (!stackEmpty(ptrbuque))
        {
            Node<puerto_t> *ptrdestino = search(destino, ps, criteriaMuelles);
            if (!stackEmpty(ptrdestino))
            {
                ptrorigen->data.n_buques--;
                ptrdestino->data.n_buques++;
                insert(ptrbuque->data, ptrdestino->data.buque, criteriaBanderaBuque);

                cout << endl << ptrorigen->data << endl;
                cout << endl << ptrdestino->data;
            }
        }
    }
}

int main()
{
    Node<puerto_t> *ps = nullptr;

    readbin(DATA_FILE, ps);

    stackPrint(ps);
    cout << setfill('-') << setw(80) << '-' << endl;
    first_prompt(ps);
    cout << setfill('-') << setw(80) << '-' << endl;
    second_prompt(ps);
    cout << setfill('-') << setw(80) << '-' << endl;

    destroy(ps);

    return 0;
}
