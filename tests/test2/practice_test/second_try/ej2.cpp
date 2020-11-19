#include <iostream>
#include <fstream>

#include "./linkedlists/linkedLists.h"
#include "./rwstring/rwstring.h"

#define DATA_FILE "./archivo.bin"

#define NOMBRE_SIZE 14

using namespace std;

typedef struct rawdata {
   string nombre = "";
   int plazo = 0;
   int cantidad = 0;
   double cotizacion = 0;
} rawdata_t;

typedef struct acciones {
    string nombre = "";
    int n_operacionestotal = 0;
    int n_operacioneshigh = 0;
    int acciones = 0;
} acciones_t;

fstream& operator >> (fstream &fs, rawdata_t& data) {
    data.nombre =  readstring(fs, NOMBRE_SIZE);
    fs.read(reinterpret_cast<char *>(&data.plazo), sizeof(data.plazo));
    fs.read(reinterpret_cast<char *>(&data.cantidad), sizeof(data.cantidad));
    fs.read(reinterpret_cast<char *>(&data.cotizacion), sizeof(data.cotizacion));
    return fs;
}

ostream& operator << (ostream &os, const rawdata_t& data) {
    os << data.nombre << ", " << data.plazo << ", "
        << data.cantidad << ", " << data.cotizacion;
    return os;
}

ostream& operator << (ostream &os, const acciones_t& data) {
    os << data.nombre << ", " << data.acciones ;
    return os;
}

int criteriaNombres(acciones_t a, acciones_t b) {
    if (a.nombre == b.nombre) {
        return 0;
    }

    else return a.nombre > b.nombre ? 1 : -1;
}

int readbin(string filename, Node<acciones_t>* &ps) {
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    acciones_t acc;
    rawdata_t data;
    while(file >> data) {
        acc.nombre = data.nombre;
        Node<acciones_t> *bar = insert_unique(acc, ps, criteriaNombres);
        //bar->data.acciones += data.cantidad;
        if(data.cantidad > 3000) {
            bar->data.n_operacioneshigh++;
        }
        bar->data.n_operacionestotal++;
    }

    file.close();

    return 0;
}

void THEprint(Node<acciones_t>* acc) {
    while(!stackEmpty(acc)) {
        cout << acc->data.nombre << ", " << acc->data.n_operacionestotal
            << ", " << (float) 100 * acc->data.n_operacioneshigh / acc->data.n_operacionestotal
            << "%" << endl;
        acc = acc->next;
    }
}

int main(void) {
    Node<acciones_t>* ps = nullptr;
    readbin(DATA_FILE, ps);
    THEprint(ps);
    stackErase(ps);

    return 0;
}
