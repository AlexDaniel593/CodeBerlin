/***********************************************************************
 * Module:  Stack.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#ifndef STACK_H
#define STACK_H

#include "Nodo.h"

template <class T>
class Pila {
private:
    Nodo<T>* topNode;

public:
    Pila();
    ~Pila();
    T top() const;
    void pop();
    bool empty() const;
    void push(const T&);
    int size() const;
    void print() const;

};

#endif