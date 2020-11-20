/*
 * ALUMNO: SAVINELLI ROBERTO NICOLAS
 * LEGAJO: 1645407
 * DNI: 41757815
 *
 */

#include <iostream>
#include <fstream>

#include "./listascomp.hpp"
#include "./listasordc.hpp"
#include "./rwstring.hpp"

#define DATA_FILE "./Datos1.bin"

#define CEREAL_SIZE 8
#define PAIS_SIZE 10
#define NAVIERA_SIZE 10

using namespace std;

typedef struct registro {
   string cereal = "";
   string pais = "";
   string naviera = "";
   double peso = 0.0;
   int compras = 0;
} registro_t;

typedef struct pedidos {
    string cereal = "";
    int cantidad = 0;
    double peso = 0.0;
} pedidos_t;

fstream& operator >> (fstream &fs, registro_t& reg) {
    reg.cereal =  readstring(fs, CEREAL_SIZE);
    reg.pais =  readstring(fs, PAIS_SIZE);
    reg.naviera =  readstring(fs, NAVIERA_SIZE);
    fs.read(reinterpret_cast<char *>(&reg.peso), sizeof(reg.peso));
    fs.read(reinterpret_cast<char *>(&reg.compras), sizeof(reg.compras));
    return fs;
}

ostream& operator << (ostream &os, const registro_t& reg) {
    os << reg.cereal << ", " << reg.pais << ", "
        << reg.naviera << ", " << reg.peso << ", " << reg.compras;
    return os;
}

ostream& operator << (ostream &os, const pedidos_t& ped) {
    os << ped.cereal << ", " << ped.cantidad << ", " << ped.peso;
    return os;
}

int criterioCerealCant(pedidos_t a, pedidos_t b) {
    if (a.cereal == b.cereal) {
        if (a.cantidad == b.cantidad) {
            return 0;
        }
        else return a.cantidad > b.cantidad ? 1 : -1;
    }
    else return a.cereal > b.cereal ? 1 : -1;
}

int solve(string filename, Nodo<pedidos_t>* &ps, int (*criterio)(pedidos_t, pedidos_t)) {
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    pedidos_t pedidos;
    registro_t data;

    while(file >> data) {
        pedidos.cereal = data.cereal;
        pedidos.peso = data.peso;
        pedidos.cantidad = data.compras;

        if(data.compras != 0) {
            if ((data.peso / data.compras) > 20){
                insertar(pedidos, ps, criterio);
            }
        }
    }

    file.close();

    return 0;
}

template <typename T> void borrarLista(Nodo<T>* &lista)
{
	while (lista != nullptr) {
        pop(lista);
    }
}

int main(void) {
    Nodo<pedidos_t>* ps = nullptr;

    solve(DATA_FILE, ps, criterioCerealCant);
    mostrar(ps);
    borrarLista(ps);

    return 0;
}
