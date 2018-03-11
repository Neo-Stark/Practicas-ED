#include "pila_max_vd.h"

void Pila_max::copiar(const Pila_max &p)
{
    pila.redimensionar(p.pila.dimension());
    for (int i = 0; i < pila.dimension(); i++)
        pila[i] = p.pila.componente(i);
}

Pila_max::Pila_max(const Pila_max &p)
{
    copiar(p);
}

void Pila_max::push(const int &elem)
{
    elemento nuevo;
    nuevo.elem = elem;
    if (empty())
        nuevo.maximo = elem;
    else
        nuevo.maximo = elem > max() ? elem : max();

    pila.redimensionar(pila.dimension() + 1);
    pila.asignar_componente(pila.dimension() - 1, nuevo);
}

elemento Pila_max::top()
{
    elemento cero;
    if (!empty())
        return pila[pila.dimension() - 1];
    else
        return cero;
}
const elemento Pila_max::top() const
{
    elemento cero;
    if (!empty())
        return pila.componente(pila.dimension() - 1);
    else
        return cero;
}

Pila_max &
Pila_max::operator=(const Pila_max &p)
{
    if (this != &p)
    {
        copiar(p);
    }
    return *this;
}