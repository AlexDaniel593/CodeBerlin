/***********************************************************************
 * Module:  Nodo.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template <class T>
class Nodo {
private:
    T data;
    Nodo<T>* next;

public:
    Nodo(const T&);
    T getData(void) const;
    Nodo<T>* getNext(void) const;
    void setNext(Nodo<T>*);
    
};

#endif