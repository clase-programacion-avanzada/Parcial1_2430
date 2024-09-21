#ifndef VUELO_H
#define VUELO_H
#include "Asiento.h"
// Include any necessary libraries here

// Define your class here

struct Vuelo {
    string codigo;
    string origen;
    string destino;
    string fecha;
    Asiento* asientos;
};
#endif // VUELO_H