#ifndef ASIENTO_H
#define ASIENTO_H
#include "Pasajero.h"

/*
    Punto 1 
    Definir la estructura Pasajero y Asiento: 
    Escribir la definición de la estructura Pasajero y Asiento.
*/
struct Asiento {
    int numero;
    bool ocupado;
    Pasajero pasajero;
};

#endif // ASIENTO_H