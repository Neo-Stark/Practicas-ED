#ifndef __PILA_MAX_H__
#define __PILA_MAX_H__

#include <cassert>
#include <iostream>

using namespace std;

/***
   *  @brief T.D.A. Pila_max
   *
   *
   * Una instancia @e c del tipo de dato abstracto Pila_max sobre un dominio @e T es
   * un conjunto de elementos del mismo tipo con un funcionamiento @e LIFO
   * (Last In, First Out}). En una pila, las operaciones de inserción y borrado
   * tienen lugar en uno de los extremos, denominado @e tope de la pila. Pila_max
   * se caracteriza por tener en el tope al máximo de los elementos
   *
   * Si n=0 diremos que la pila está vacía.
   *
   * En este módulo decidiremos que implementación de pila queremos usar:
   *
   * La primera es la implementación de Pila_max basada en un vector dinámico y
   * la segunda se basa en una cola
   */



#define CUAL_COMPILA 1
#if CUAL_COMPILA == 1
#include "pila_max_vd.h"
#else
#include "pila_max_cola.h"
#endif

/**
   * @brief Sobrecarga del operador << para elemento
   * @return salida por os de la siguiente forma:
   * Elemento: elemento.ele  Máximo: elemento.max
   */
ostream &operator<<(ostream &os, const elemento &elem)
{
    os << "Elemento: " << elem.elem
       << "  Máximo: " << elem.maximo << endl;

    return os;
}

#endif