#ifndef COMPANIA_H
#define COMPANIA_H
#include "Avion.h"
#include "Vuelo.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct Compania {
    int numeroAviones;
    Avion* aviones;

    Compania() {
        numeroAviones = 0;
        aviones = nullptr;
    }
};

//Punto 2: Agregar un avión a la compañía
//Desarrollar una función que permita agregar un avión a la compañía, 
//en la que se envíe como parámetro la compañía por referencia y el avión a agregar por valor. 

void agregarAvion(Compania &compania, Avion avion) {
    //Crear un nuevo arreglo de aviones con un espacio adicional
    Avion* aviones = new Avion[compania.numeroAviones + 1];
    
    //Copiar los aviones de la compania al nuevo arreglo
    for (int i = 0; i < compania.numeroAviones; i++) {
        aviones[i] = compania.aviones[i];
    }

    //Agregar el nuevo avion al final del arreglo
    aviones[compania.numeroAviones] = avion;
    //Eliminar el arreglo anterior
    delete[] compania.aviones;
    //Actualizar el arreglo de aviones de la compania
    compania.aviones = aviones;
    compania.numeroAviones++;
}

// Punto 3 : Buscar un avión por código
// Desarrollar una función que, dado el código de un avión, lo busque en el arreglo de aviones de la compañía
// y lo retorne por referencia. Si el avión no se encuentra, debe retornar nullptr.
Avion* buscarAvionPorCodigo(Compania& compania, string codigoABuscar) {
    for (int i = 0; i < compania.numeroAviones; i++) {
        string codigo = compania.aviones[i].codigo;
        if (codigo == codigoABuscar) {
            return &compania.aviones[i];
        }
    }
    return nullptr;
}
/*
    Punto 4: Agregar un vuelo a un avión
    Desarrollar una función que, a partir de una cadena de caracteres con la línea del vuelo 
    en el archivo de texto, busque el avión con el método buscar y agregue el vuelo 
    al arreglo de vuelos del avión.
*/
void agregarVueloAAvion(Compania& compania, string lineaVuelo) {
    //Línea de vuelo de la forma 
    //"CódigoAvion,CódigoVuelo,Origen,Destino,Fecha"
    //"6052,AV1120,Bogota,Rio de Janeiro,21/11/2024"

    //Extraer los datos de la línea
    stringstream ss(lineaVuelo);
    string codigoAvion, codigoVuelo, origen, destino, fecha;
    
    getline(ss, codigoAvion, ',');
    getline(ss, codigoVuelo, ',');
    getline(ss, origen, ',');
    getline(ss, destino, ',');
    getline(ss, fecha, ',');

    //Buscar el vuelo en el avión
    Avion *avion = buscarAvionPorCodigo(compania, codigoAvion);
    //Si el vuelo no existe, crearlo

    if (avion != nullptr) {
        
        //Crear un nuevo arreglo de vuelos con un espacio adicional
        Vuelo* nuevosVuelos = new Vuelo[avion->numeroVuelos+1];

        //Copiar los vuelos del avión al nuevo arreglo
        for (int i = 0; i < avion->numeroVuelos; i++) {
            nuevosVuelos[i] = avion->vuelos[i];
        }

        //Agregar el nuevo vuelo al final del arreglo
        nuevosVuelos[avion->numeroVuelos].codigo = codigoVuelo;
        nuevosVuelos[avion->numeroVuelos].origen = origen;
        nuevosVuelos[avion->numeroVuelos].destino = destino;
        nuevosVuelos[avion->numeroVuelos].fecha = fecha;
        //Eliminar el arreglo anterior
        delete[] avion->vuelos;
        //Actualizar el arreglo de vuelos del avión
        avion->vuelos = nuevosVuelos;
        avion->numeroVuelos++;
    }
}

/*
    Punto 5: Leer el archivo de texto:
    Desarrollar una función que lea el archivo de texto llamado vuelos.txt, 
    utilizando los métodos anteriores.
*/

Compania leerArchivo() {
    Compania compania;

    fstream file;

    file.open("vuelos.txt", ios::in);

    if (file.fail()) {
        return compania;
    }
    //Ejemlo de archivo
    /*
    Avianca
    6052-20,6053-30
    6052,AV1120,Bogota,Rio de Janeiro,21/11/2024
    6052,AV1121,Rio de Janeiro,Bogota,12/12/2024
    6053,AV1240,Bogota,Cali,13/10/2024
    6053,AV1242,Medellin,Bucaramanga,10/02/2025
    #
    American Airlines
    2040-25
    2040,AA1120,Bogota,Miami,10/05/2024
    2040,AA1124,Bogota,Miami,19/05/2022
    2040,AA1121,Miami,Madrid,12/12/2024
    #
    */
    //Primero se debe leer el nombre de la empresa de los primeros dos aviones
    //Avianca
    string nombreEmpresa;
    while(getline(file, nombreEmpresa)) {

        //Después, se debe leer el código y número de asientos de cada avión
        //6052-20,6053-30
        string lineaAviones;
        getline(file, lineaAviones);
        stringstream ss(lineaAviones);

        //Extraer los códigos y número de asientos de cada avión
        //6052-20
        string lineaAvion; 

        //Dentro de este while se extraen los aviones y se agregan a la compañía sin vuelos
        while(getline(ss,lineaAvion,',')) {
            stringstream ssAvion(lineaAvion);
            string codigoVuelo, numeroAsientos;
            //Extraer el código y número de asientos de cada avión
            //6052
            getline(ssAvion, codigoVuelo, '-');
            //20
            getline(ssAvion, numeroAsientos, '-');

            //Crear un nuevo avión
            Avion avion;
            avion.nombreEmpresa = nombreEmpresa;
            avion.codigo = codigoVuelo;
            avion.numeroAsientos = stoi(numeroAsientos);
            avion.numeroVuelos = 0;
            avion.vuelos = nullptr;

            //Agregar el avión a la compañía
            agregarAvion(compania, avion);
    }

    //Leer los vuelos de cada avión
    //6052,AV1120,Bogota,Rio de Janeiro,21/11/2024
    string lineaVuelo;
    
    do {
        getline(file, lineaVuelo);

        if (lineaVuelo != "#") {
            agregarVueloAAvion(compania, lineaVuelo);
        }

        //Mientras no se llegue al final de los vuelos
    } while (lineaVuelo != "#");
    
    }
    file.close();

    return compania;

}

/*
    Punto 6 Generar reporte de vuelos por ciudad de origen:
    Dada una cadena de caracteres, buscar los vvuelos cuyo otigen coincida con dicha cadena.
    Si se encuentran vuelos, generar un archivo de texto llamado vuelosOrigen.txt y un archivo binario
    llamado vuelosOrigen.dat con la información de los vuelos.
*/

void generarReporte(Compania& compania, string ciudadOrigen) {
    fstream file;
    file.open("vuelosOrigen.txt", ios::out);
    fstream fileBin;
    fileBin.open("vuelosOrigen.dat", ios::out | ios::binary);

    for (int i = 0; i < compania.numeroAviones; i++) {
        Avion avion = compania.aviones[i];
        for (int j = 0; j < avion.numeroVuelos; j++) {
            Vuelo vuelo = avion.vuelos[j];
            if (vuelo.origen == ciudadOrigen) {
                file << "Avion: " << avion.codigo << " Vuelo: " << vuelo.codigo << " Origen: " << vuelo.origen << " Destino: " << vuelo.destino << " Fecha: " << vuelo.fecha << endl;
                fileBin.write((char*)&vuelo, sizeof(Vuelo));
            }
        }
    }

    file.close();
    fileBin.close();
}

#endif // COMPANIA_H

