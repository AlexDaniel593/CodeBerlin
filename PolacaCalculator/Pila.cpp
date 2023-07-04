/***********************************************************************
 * Module:  Stack.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include "Pila.h"

template <typename T>
Pila<T>::Pila() {
    topNode = nullptr;
} 

template <typename T>
Pila<T>::~Pila() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
T Pila<T>::top() const {
    if (empty()) {
        throw std::runtime_error("La pila está vacía");
    }
    return topNode->getData();
}

template <typename T>
void Pila<T>::pop() {
    if (empty()) {
        throw std::runtime_error("La pila está vacía");
    }
    Nodo<T>* temp = topNode;
    topNode = topNode->getNext();
    delete temp;
}

template <typename T>
bool Pila<T>::empty() const {
    return topNode == nullptr;
}

template <typename T>
void Pila<T>::push(const T& value) {
    Nodo<T>* newNode = new Nodo<T>(value);
    newNode->setNext(topNode);
    topNode = newNode;
}

template <typename T>
int Pila<T>::size() const {
    int count = 0;
    Nodo<T>* current = topNode;

    while (current != nullptr) {
        count++;
        current = current->getNext();
    }

    return count;
}

template <typename T>
void Pila<T>::print() const {
    Nodo<T>* current = topNode;

    while (current != nullptr) {
        std::cout << current->getData()<<endl;
        current = current->getNext();
    }

    std::cout << std::endl;
}



