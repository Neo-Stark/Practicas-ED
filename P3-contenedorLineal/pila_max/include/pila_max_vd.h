/**
   * @file pila_max_vd.h
   * @brief Fichero cabecera del TDA pila_max_vd
   * Pila ordenada implementada a partir de VDG.h
   */

#ifndef __COLA_MAX_VD__
#define __COLA_MAX_VD__

#include "VDG.h"


using namespace std;
struct elemento
{
    int elem;   ///< Elemento a almacenar
    int maximo; ///< Elemento Máximo
};

/**
   *  @brief T.D.A. Pila_max_vd
   *
   * La descripción de este T.D.A coincide con la del T.D.A @pila_max.h
   * Este archivo contiene el módulo realizado a partir de un vector dinámico
   *
   *
   */

class Pila_max
{
  private:
    VectorDinamico<elemento> pila;
    /**
     * @brief Copiar pila
     * @param p Pila a copiar
     * Atributo privado que copia la pila dada como argumento en el objeto implícito
     */
    void copiar(const Pila_max &p);

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
    Pila_max(const Pila_max &p);

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
        pila.redimensionar(pila.dimension() - 1);
    }

    /**
   * @brief Devuelve el tope de la pila
   */
    elemento top();
    
    /**
   * @brief Devuelve el tope de la pila constante
   */
    const elemento top() const;


    /**
   * @brief Comprueba si la pila está vacia
   */
    bool empty() const
    {
        return pila.dimension() == 0;
    }

    /**
   * @brief Devuelve el número de elementos de la pila
   */
    int numero_elementos() const
    {
        return pila.dimension();
    }

    /**
   * @brief Máximo de la pila
   * @return elemento máximo
   */
    int max() const
    {
        return top().maximo;
    }

    /**
   * @brief Sobrecarga operador de asignación
   * @param p Pila a asignar
   * @return Objeto implícito
   */
    Pila_max &operator=(const Pila_max &p);
};
#endif /* __COLA_MAX_VD__ */