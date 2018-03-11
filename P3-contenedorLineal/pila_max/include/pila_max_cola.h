
/**
   * @file pila_max_cola.h
   * @brief Fichero cabecera del TDA pila_max_cola
   * Pila con máximo implementada a partir de cola.h
   */

#ifndef __PILA_MAX_COLA_H__
#define __PILA_MAX_COLA_H__

#include <iostream>
#include <cassert>
#include "cola.h"

using namespace std;

struct elemento
{
    int elem;   ///< Elemento a almacenar
    int maximo; ///< Elemento Máximo
};

/**
   *  @brief T.D.A. Pila_max_Cola
   *
   * La descripción de este T.D.A coincide con la del T.D.A @pila_max.h
   * Este archivo contiene el módulo realizado a partir de colas
   *
   *
   */

class Pila_max
{
  private:
    Cola<elemento> pila;

  public:
    /**
   * @brief Constructor por defecto
   * @post pila vacía
   */
    Pila_max() = default;

    /**
   * @brief Constructor de copia
   * @param p Pila a copiar en el objeto implícito
   */
    Pila_max(const Pila_max &p)
    {
        pila = p.pila;
    }

    /**
   * @brief Agregar un elemento a la pila
   * @param elem elemento a insertar
   * @post pila con el elemento máximo en elemento.max
   */
    void push(const int &elem);

    /**
   * @brief Eliminar el último elemento añadido
   * @post Pila sin el tope
   */
    void pop()
    {
        pila.quitar();
    }

    /**
   * @brief Devuelve el tope de la pila
   */
    elemento top()
    {
        return pila.frente();
    }
    /**
   * @brief Devuelve el tope de la pila constante
   */
    const elemento top() const
    {
        return pila.frente();
    }

    /**
   * @brief Comprueba si la pila está vacia
   */
    bool empty()
    {
        return pila.vacia();
    }

    /**
   * @brief Devuelve el número de elementos de la pila
   */
    int numero_elementos() const
    {
        return pila.num_elementos();
    }

    /**
   * @brief Máximo de la pila
   * @return elemento máximo
   */
    int max() const
    {
        return pila.frente().maximo;
    }

    /**
   * @brief Sobrecarga operador de asignación
   * @param p Pila a asignar
   * @return Objeto implícito
   */
    Pila_max &operator=(const Pila_max &p);
};

#endif /*__PILA_MAX_COLA_H__*/