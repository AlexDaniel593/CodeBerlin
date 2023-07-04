/***********************************************************************
 * Module:  Operaciones.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023 
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include "Operaciones.h"
#include <iostream>
using namespace std;
double Operaciones::sin(double angulo )
{
    double x = angulo;
    double result,precission;
    result = 0;
    precission = 0;
    int sign=0,final_sign;
    final_sign = 0;
    const double pi = 3.141592654;
    while (x > pi) {
        x = x - pi;
        final_sign = final_sign + 1;
    }
    for (int i = 1; i <= 11; i = i + 2) {
        precission = potencia(-1, sign)*(potencia(x,i) / factorial(i));

        result = result + precission;
        sign = sign + 1;
        
    }
    if (final_sign % 2 != 0) {
        result = result * -1;
    }
    return result;
}


double Operaciones::cos(double angulo)
{
    
    double result = 0; 
    int presicion = 8; 
    const double pi = 3.141592654;
    int cont = 0;
    while (angulo > pi) {
        angulo = angulo - pi;
        cont++;
 
    }
    for (int i = 0; i < presicion; i++)
    {
        result += ((potencia(-1, i)) / factorial(2 * i)) * potencia(angulo, 2 * i);
    }
    if (cont%2==1) {
       result = result * -1;
    }
    return result;
}

double Operaciones::tan(double angulo)
{
    double tan;
    tan = Operaciones::sin(angulo) / Operaciones::cos(angulo);
    return tan;
}

long Operaciones::factorial(int n)
{
    //Funciona hasta 16! 
    if (n < 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

double Operaciones::potencia(double num, double pot)
{
    double result=1;
    if (pot == 0) {
        return 1;
    }
    if (pot == 1) {
        return num;
    }
    if (pot == 0.5) {
        double raiz = raizCuadrada(num);
        return raiz;
    }
    for (int i = 0; i < pot; i++) {
        result = result * num;
    }
    return result;
}

double Operaciones::raizCuadrada(double num) {
    double raiz = 0;
    while ((num - raiz * raiz) > 0.00001) {
        raiz = raiz + 0.00001;
    }
    return raiz;
}

double Operaciones::raizCubica(double num) {
    double raiz = 0;
    while ((num - raiz * raiz * raiz) > 0.00001) {
        raiz = raiz + 0.00001;
    }
    return raiz;
}
