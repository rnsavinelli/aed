/*
 * ALUMNO: SAVINELLI ROBERTO NICOLAS
 * LEGAJO: 1645407
 * DNI: 41757815
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>

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
    string pais = "";
    string naviera = "";
    double peso = 0.0;
    int compras = 0;
} pedidos_t;

typedef struct cereal {
    string cereal = "";
    double promedio = 0.0;
    double total_peso = 0;
    int total_compras = 0;
    Nodo<pedidos_t> * pedidos = nullptr;
} cereal_t;

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
    os << ped.naviera << ", " << ped.peso;
    return os;
}

ostream& operator << (ostream &os, const cereal_t& cer) {
    os << setfill('-') << setw(80) << '-' << endl
        << cer.cereal << ", " << cer.total_peso << ", " << cer.total_compras
        << ", " << cer.promedio << endl << endl;
    mostrar(cer.pedidos);
    return os;
}

int criterioCereal(cereal_t a, cereal_t b) {
    if (a.cereal == b.cereal) {
        return 0;
    }
    else return a.cereal < b.cereal ? 1 : -1;
}

double calcular_promedio(Nodo<pedidos_t>* lista) {
    double sum = 0;
    int n = 0;

    while(lista != nullptr) {
        sum += lista->dato.peso;
        n += lista->dato.compras;
        lista = lista->sig;
    }

    return n == 0 ? 0.0 : sum / n;
}

int solve(string filename, Nodo<cereal_t>* &ps, int (*criterio)(cereal_t, cereal_t)) {
    fstream file;
    file.open(filename, ios::binary | ios::in);

    if(!file.is_open()) {
        return -1;
    }

    pedidos_t pedido;
    cereal_t cereal;
    registro_t data;

    while(file >> data) {
        cereal.cereal = data.cereal;

        pedido.pais = data.pais;
        pedido.naviera = data.naviera;
        pedido.peso = data.peso;
        pedido.compras = data.compras;

        Nodo<cereal_t> * plocation = insertar_unico(cereal, ps, criterio);
        agregar(plocation->dato.pedidos, pedido);

        plocation->dato.total_peso += pedido.peso;
        plocation->dato.total_compras += pedido.compras;
    }

    Nodo<cereal_t>* aux = ps;
    while(aux != nullptr) {
        aux->dato.promedio = calcular_promedio(aux->dato.pedidos);
        aux = aux->sig;
    }

    file.close();

    return 0;
}

void borrarListaCereales(Nodo<cereal_t> *s) {
    while(s != nullptr) {
        while(s->dato.pedidos != nullptr) {
            pop(s->dato.pedidos);
        }
        pop(s);
    }
}

int main(void) {
    Nodo<cereal_t>* ps = nullptr;

    solve(DATA_FILE, ps, criterioCereal);
    mostrar(ps);
    cout << setfill('-') << setw(80) << '-' << endl;
    borrarListaCereales(ps);

    return 0;
}
