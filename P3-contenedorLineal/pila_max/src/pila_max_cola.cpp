#include "pila_max_cola.h"

void Pila_max::push(const int& elem)
{
    elemento nuevo;
    nuevo.elem = elem;
    if (empty()){
        nuevo.maximo = elem;
        pila.poner(nuevo);
    }
    else
    {
        nuevo.maximo = elem > max() ? elem : max();
        Cola<elemento> pila_aux;
        pila_aux.poner(nuevo);
        int elementos = numero_elementos();
        for (int i = 0; i < elementos; i++)
        {
            pila_aux.poner(pila.frente());
            pila.quitar();
        }
        pila = pila_aux;
    }
}

Pila_max& Pila_max::operator=(const Pila_max &p){
    if (this != &p)
        pila = p.pila;
    return *this;
}