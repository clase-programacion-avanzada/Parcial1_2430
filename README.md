# Parcial 2430 - Programación Avanzada

## I. (20 puntos) Conceptos

1. Cuando se pasa un arreglo como parámetro a una función, éste se pasa como una copia.
   - Verdadero
   - Falso

   <details>
   <summary>Respuesta</summary>
   Falso. Se pasa como referencia, no como una copia.
   </details>

2. ¿Qué hará el siguiente código?
    ```cpp
        int arr[5] = {1,10, 8, 3, 4, 51};
        int ptr = arr;
        * (ptr + 2) = 10;
    ```
    - Asignará el valor 10 al primer elemento de arr.
    - Asignará el valor 10 al tercer elemento de arr.
    - Asignará el valor 10 al segundo elemento de arr.
    - Asignará el valor 10 al cuarto elemento de arr.

    <details>
    <summary>Respuesta</summary>
    Asignará el valor 10 al tercer elemento de `arr`.
    </details>

3. ¿Cuál es el formato correcto para abrir un archivo de texto en modo de escritura en C++?
   - `ofstream file("archivo.txt", ios::in);`
   - `ifstream file("archivo.txt", ios::out);`
   - `ofstream file("archivo.txt", ios::out);`
   - `fstream file("archivo.txt", ios::in);`

   <details>
   <summary>Respuesta</summary>
   `ofstream file("archivo.txt", ios::out);` es el formato correcto.
   </details>

4. En C++, el operador new se utiliza para liberar memoria asignada dinámicamente.
   - Verdadero
   - Falso

   <details>
   <summary>Respuesta</summary>
   Falso. El operador `new` se utiliza para asignar memoria, no para liberarla. El operador `delete` se utiliza para liberar memoria.
   </details>

5. ¿Cuál de las siguientes sentencias no es correcta?
   - char frase [] = "Esta es una frase";
   - char * frase2 = "Esta es una frase";
   - string frase3 = "Esta es una frase";
   - string * frase4 = "Esta es una frase";

   <details>
   <summary>Respuesta</summary>
   La sentencia incorrecta es `string * frase4 = "Esta es una frase";`, en este caso, la variable `frase4` es un apuntador a `string`, esto quiere decir que la asignación espera una dirección de memoria, no un valor.
   </details>

6. ¿Cuál de las siguientes notaciones es correcta para acceder al nombre de la estructura persona utilizando el apuntador perPtr?
    ```cpp
    struct Persona {
         string nombre;
         int edad;
         float estatura;
    };

    int main() {
        Persona persona;
        Persona * perPtr = &persona;

        return 0;
    }
    ```
    - `perPtr.nombre`
    - `perPtr->nombre`
    - `*(perPtr->nombre)`
    - `*(perPtr)->nombre`

   <details>
   <summary>Respuesta</summary>
   La notación correcta es `perPtr->nombre`.
   </details>

7. ¿En C++ al abrir un archivo solamente se puede abrir como escritura o lectura, pero no ambos?
    - Verdadero
    - Falso

   <details>
   <summary>Respuesta</summary>
   Falso. Un archivo puede abrirse tanto para escritura como para lectura usando modos combinados como `ios::in | ios::out` y el tipo de dato fstream.
   </details>

8. ¿Qué función de C++ se utiliza para asignar memoria dinámica para un arreglo?
    - `malloc`
    - `calloc`
    - `new`
    - `free`

   <details>
   <summary>Respuesta</summary>
   En C++, se utiliza `new` para asignar memoria dinámica.
   </details>

9. Un struct en C++ puede contener tanto datos como funciones.
    - Verdadero
    - Falso

   <details>
   <summary>Respuesta</summary>
   Verdadero. Un `struct` en C++ puede contener tanto variables (datos) como funciones.
   </details>

10. ¿Cuál es la forma correcta de liberar memoria asignada dinámicamente para un arreglo en C++?
    - `delete p;`
    - `free(p);`
    - `delete p[];`
    - `delete[] p;`
    
    <details>
    <summary>Respuesta</summary>
    La forma correcta es `delete[] p;`.
    </details>

## II. (80 puntos) Gestión de Reservas

Una compañía aérea necesita desarrollar un sistema básico para gestionar aviones, vuelos y pasajeros. Como desarrollador, la tarea a su cargo es implementar un conjunto de funcionalidades que permitan gestionar esta información.

**Información de un pasajero:**

1. **Nombre**: cadena de caracteres de 50 bytes.
2. **Apellido**: cadena de caracteres de 50 bytes.
3. **Documento**: entero (int).
4. **Nacionalidad**: cadena de caracteres de 30 bytes.

### Información de un asiento:
1. **Número de asiento**: entero (int).
2. **Ocupado**: booleano; `false` si está vacío y `true` si está ocupado.
3. **Pasajero**: estructura `Pasajero`; hay un pasajero, en este campo se almacenan sus datos.

### Información de un vuelo:
1. **Código de vuelo**: cadena de caracteres de 10 bytes.
2. **Origen**: cadena de caracteres de 50 bytes.
3. **Destino**: cadena de caracteres de 50 bytes.
4. **Fecha**: cadena de caracteres de 11 bytes en formato `DD/MM/AAAA`.
5. **Asientos**: arreglo dinámico; la cantidad de asientos varía según el avión.

### Información de un avión:
1. **Nombre de la empresa**: cadena de caracteres de 50 bytes.
2. **Código del avión**: cadena de caracteres de 10 bytes.
3. **Número de asientos**: entero (int).
4. **Vuelos**: arreglo dinámico, la cantidad de vuelos varía.

### Información de la compañía:
1. **Aviones**: arreglo dinámico; la compañía puede agregar más aviones a una empresa específica.
2. **Número de aviones**: entero (int).

La compañía aérea ya cuenta con un archivo de texto llamado `vuelos.txt` que contiene información sobre vuelos y aviones. Un ejemplo del archivo es el siguiente:

    ```
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
    ```
Por ejemplo, en la primera línea del archivo se encuentra el nombre de la empresa (Avianca). En la segunda línea se especifican los códigos y el número de asientos de cada avión, separados por el carácter "_".

Si hay más de un avión, se separa por comas; por ejemplo, Avianca tiene dos aviones, el código del primero es 6052 con 20 asientos y el del segundo es 6053 con 30 asientos.

Finalmente, en las demás líneas se encuentran los vuelos. El primer valor es el código del avión (6052), seguido por el código del vuelo (AV1120), el origen (Bogotá), el destino (Rio de Janeiro) y la fecha (21/11/2024). El carácter "#" indica que ya no hay más vuelos asignados a la empresa y que se pasa a la siguiente.

A partir de la información proporcionada, se le solicita implementar los siguientes servicios:

1. **(5 puntos) Definir la estructura de pasajero y asiento**: escribir la definición de la estructura de pasajero y asiento.</br></br>
2. **(15 puntos) Agregar un avión a la compañía**: desarrollar una función que permita agregar un avión a la compañía, en la que se envíe como parámetro la compañía por referencia y el avión por valor.</br></br>
3. **(5 puntos) Buscar avión por código**: desarrollar una función que, dado el código de un avión, lo busque en el arreglo de aviones de la compañía y lo retorne por referencia. Si no lo encuentra, debe retornar `nullptr`.</br></br>
4. **(20 puntos) Agregar un vuelo a un avión**: desarrollar una función que, a partir de una cadena de caracteres (línea del vuelo en el archivo de texto), busque el avión con el método anterior y agregue el vuelo al arreglo de vuelos del avión.</br></br>
5. **(20 puntos) Leer el archivo de texto**: desarrollar una función que lea un archivo de texto llamado `vuelos.txt`, utilizando los métodos anteriores para agregar aviones y vuelos registrados en la compañía.</br></br>
6. **(15 puntos) Generar reporte de vuelos por ciudad de origen**: dada una cadena de caracteres, buscar los vuelos cuyo origen coincida con dicha cadena. Si se encuentran vuelos, generar un archivo de texto llamado `vuelosOrigen.txt` y un archivo binario llamado `vuelosOrigen.dat` con la información de los vuelos.