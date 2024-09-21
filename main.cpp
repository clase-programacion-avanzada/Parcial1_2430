#include <iostream>
#include "libs/Compania.h"

using namespace std;

int main() {
    

    Compania compania = leerArchivo();

    generarReporte(compania, "Bogota");
    
    return 0;
}