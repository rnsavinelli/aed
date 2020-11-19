#include <iostream>
#include <fstream>

#include "./linkedlists/linkedLists.h"
#include "./rwstring/rwstring.h"

#define DATA_FILE "./archivo.bin"

#define CANT_PLAZOS 5

#define NOMBRE_SIZE 14

using namespace std;

typedef struct rawdata {
   string nombre = "";
   int plazo = 0;
   int cantidad = 0;
   double cotizacion = 0;
} rawdata_t;

fstream& operator >> (fstream &fs, rawdata_t& data) {
    data.nombre =  readstring(fs, NOMBRE_SIZE);
    fs.read(reinterpret_cast<char *>(&data.plazo), sizeof(data.plazo));
    fs.read(reinterpret_cast<char *>(&data.cantidad), sizeof(data.cantidad));
    fs.read(reinterpret_cast<char *>(&data.cotizacion), sizeof(data.cotizacion));
    return fs;
}

ostream& operator << (ostream &os, const rawdata_t& data) {
    os << data.nombre << ", " << data.cotizacion;
    return os;
}

int readbin(string filename, Node<rawdata_t>* ps[CANT_PLAZOS]) {
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    rawdata_t data;
    while(file >> data) {
        append(ps[data.plazo], data);
    }

    file.close();

    return 0;
}

int sum(Node<rawdata>* ps){
    int sum = 0;
    while(!stackEmpty(ps)) {
        sum += ps->data.cantidad;
        ps = ps->next;
    }
    return sum;
}

int solve(Node<rawdata_t>* ps[CANT_PLAZOS]) {
    int max_acciones = sum(ps[0]);
    int max_i = 0;

    for(int i = 1; i < CANT_PLAZOS; i++) {
        int curr = sum(ps[i]);
        if (curr > max_acciones) {
            max_acciones = curr;
            max_i = i;
        }
    }
    return max_i;
}

int main(void) {
    Node<rawdata_t>* ps[CANT_PLAZOS] = {nullptr};
    readbin(DATA_FILE, ps);

    int index = solve(ps);
    stackPrint(ps[index]);

    for(int i = 0; i < CANT_PLAZOS; i++) {
        stackErase(ps[i]);
    }

    return 0;
}
