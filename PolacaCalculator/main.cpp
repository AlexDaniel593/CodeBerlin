/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Module:  main.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/


#include<iostream>
#include "Polaca.h"
#include "Operaciones.h"
#include <string>
#include <conio.h>

using namespace std;

void mostrarMenu() {
    cout << "Opciones disponibles:" << std::endl;
    cout << "  + : Suma" << endl;
    cout << "  - : Resta" << endl;
    cout << "  * : Multiplicacion" << endl;
    cout << "  / : Division" << endl;
    cout << "  ^ : Potencia" << endl;
    cout << "  r : Raiz cuadrada" << endl;
    cout << "  s : Seno" << endl;
    cout << "  c : Coseno" << endl;
    cout << "  t : Tangente" << endl;
    cout << "  q : Raiz cubica" << endl;
    cout << "Ingrese la expresion matematica en notacion infija: ";
}

int main() {
    Polaca polaca;
    string expresion;

    mostrarMenu();
    getline(cin, expresion);

    Pila<char*> posfijo = polaca.convertInfijoAPosfijo(expresion);
    Pila<char> prefijo = polaca.convertInfijoAPrefijo(expresion);

    cout << "Expresion original: " << expresion << endl;
    cout << "Expresion en notacion posfija: ";
    posfijo.print();
    cout << "Expresion en notacion prefijo: ";
    prefijo.print();

    Pila<double> respuesta = polaca.resolver(expresion);
    respuesta.print();


    system("pause");

    return 0;
}

