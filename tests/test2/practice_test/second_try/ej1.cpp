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

int readbin(string filename, Node<rawdata_t>* &ps) {
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    rawdata_t data;
    while(file >> data) {
        append(ps, data);
    }

    file.close();

    return 0;
}

int main(void) {
    Node<rawdata_t>* ps = nullptr;
    readbin(DATA_FILE, ps);
    stackPrint(ps);
    stackErase(ps);

    return 0;
}
