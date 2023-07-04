/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Module:  Polaca.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "Polaca.h"

using namespace std;

Polaca::Polaca(void)
{
}


bool Polaca::isOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Polaca::isFuncion(char c) {
    return c == 's' || c == 'c' || c == 't'  || c == 'r' || c == 'q';
}

int Polaca::obtenerPrecedencia(string operador) {
    if (operador == "s" || operador == "c" || operador == "t")
        return 4;
    else if (operador == "^" || operador == "r" || operador == "q")
        return 3;
    else if (operador == "*" || operador == "/")
        return 2;
    else if (operador == "+" || operador == "-")
        return 1;
    else
        return 0;
}


Pila<string> Polaca::ConvertirExpresionPrefijaAPila(string expresionPrefija){
    Pila<string> pila;
    Pila<string> pilaOperadores;
    string infijoRevertido;

    for (auto it = expresionPrefija.rbegin(); it != expresionPrefija.rend(); ++it)
        infijoRevertido += *it;

    string numero;
    for (char c : infijoRevertido) {
        if (std::isdigit(c) || c == '.') {
            numero = c + numero; // Agregar el dígito o el punto al inicio del número
        }
        else {
            if (!numero.empty()) {
                pila.push(numero);
                numero.clear(); // Limpiar la variable para el siguiente número
            }
            if (!numero.empty() || isOperador(c) || isFuncion(c)) {
               
            }
        }
        
    }

    return pila;
}




Pila<double> Polaca::resolver(const string& expresion) {
    Pila<double> pilaOperandos;
    Pila<char> pilaOperadores;
    string infijoRevertido;

    // Revertir la expresión infija
    for (auto it = expresion.rbegin(); it != expresion.rend(); ++it) {
        if (*it == '(')
            infijoRevertido += ')';
        else if (*it == ')')
            infijoRevertido += '(';
        else
            infijoRevertido += *it;
    }

    string numero; // Variable para construir números (enteros o decimales)

    for (char c : infijoRevertido) {
        if (std::isdigit(c) || c == '.') {
            numero = c + numero; // Agregar el dígito o el punto al inicio del número
        }
        else {
            if (!numero.empty()) {
                // Si hay un número construido, convertirlo a double y agregarlo a la pila de operandos
                double valor = std::stod(numero);
                pilaOperandos.push(valor);
                numero.clear(); // Limpiar la variable para el siguiente número
            }

            if (c == '(') {
                pilaOperadores.push(c);
            }
            else if (c == ')') {
                while (!pilaOperadores.empty() && pilaOperadores.top() != '(') {
                    double operando2 = pilaOperandos.top();
                    pilaOperandos.pop();
                    double operando1 = pilaOperandos.top();
                    pilaOperandos.pop();

                    char operador = pilaOperadores.top();
                    pilaOperadores.pop();

                    double resultado = evaluarOperacion(operando1, operando2, operador);
                    pilaOperandos.push(resultado);
                }

                if (!pilaOperadores.empty() && pilaOperadores.top() == '(')
                    pilaOperadores.pop();
            }
            else if (isOperador(c) || isFuncion(c)) {
                while (!pilaOperadores.empty() && obtenerPrecedencia(pilaOperadores.top()) >= obtenerPrecedencia(c)) {
                    double operando2 = pilaOperandos.top();
                    pilaOperandos.pop();
                    double operando1 = pilaOperandos.top();
                    pilaOperandos.pop();

                    char operador = pilaOperadores.top();
                    pilaOperadores.pop();

                    double resultado = evaluarOperacion(operando1, operando2, operador);
                    pilaOperandos.push(resultado);
                }

                pilaOperadores.push(c);
            }
        }
    }

    if (!numero.empty()) {
        // Agregar el último número construido (si existe) a la pila de operandos
        double valor = std::stod(numero);
        pilaOperandos.push(valor);
    }

    while (!pilaOperadores.empty()) {
        double operando2 = pilaOperandos.top();
        pilaOperandos.pop();
        double operando1 = pilaOperandos.top();
        pilaOperandos.pop();

        char operador = pilaOperadores.top();
        pilaOperadores.pop();

        double resultado = evaluarOperacion(operando1, operando2, operador);
        pilaOperandos.push(resultado);
    }

    return pilaOperandos;
}


double Polaca::evaluarOperacion(double operand1, double operand2, const string& operador) {
    Operaciones op;

    if (operador == "+") {
        return operand1 + operand2;
    }
    else if (operador == "-") {
        return operand1 - operand2;
    }
    else if (operador == "*") {
        return operand1 * operand2;
    }
    else if (operador == "/") {
        return operand1 / operand2;
    }
    else if (operador == "^") {
        return op.potencia(operand1, operand2);
    }
    else if (operador == "s") {
        return op.sin(operand2);
    }
    else if (operador == "c") {
        return op.cos(operand2);
    }
    else if (operador == "t") {
        return op.tan(operand2);
    }
    else if (operador == "r") {
        return op.raizCuadrada(operand2);
    }
    else if (operador == "q") {
        return op.raizCubica(operand2);
    }
    return 0.0;
}
