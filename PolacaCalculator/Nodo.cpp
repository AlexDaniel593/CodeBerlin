/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(const T& value) {
    this->data = value;
    this->next = nullptr;

}

template <typename T>
T Nodo<T>::getData() const {
    return data;
}

template <typename T>
Nodo<T>* Nodo<T>::getNext() const {
    return next;
}

template <typename T>
void Nodo<T>::setNext(Nodo<T>* node) {
    next = node;
}