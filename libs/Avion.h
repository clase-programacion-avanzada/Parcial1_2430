#ifndef AVION_H
#define AVION_H
#include "Vuelo.h"
#include "Compania.h"
#include <string>
#include <sstream>

using namespace std;
// Include any necessary libraries here


struct Avion {

    string nombreEmpresa;
    string codigo;
    int numeroAsientos;
    int numeroVuelos;
    Vuelo* vuelos;
};


#endif // AVION_H