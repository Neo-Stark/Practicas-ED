#include <iostream>
#include "cronologia.h"

using namespace std;

void Cronologia::copia(const Cronologia &crono)
{
    Cronologia::const_iterator it;
    for (it = crono.cbegin(); it != crono.cend(); it++)
        this->set_evento(it->second);
}

Cronologia::Cronologia(const Cronologia &crono)
{
    copia(crono);
}

bool Cronologia::existe_fecha(int fecha)
{
    bool existe = false;
    Cronologia::iterator it = crono.find(fecha);
    if (it != end())
        existe = true;

    return existe;
}

FechaHistorica &Cronologia::obtener_fecha(int fecha)
{
    return crono[fecha];
}

void Cronologia::set_evento(const FechaHistorica &fecha)
{
    int anio = fecha.get_fecha();
    crono[anio].set_fecha(anio);
    crono[anio] += fecha;
}

Cronologia Cronologia::buscar_palabra_clave(const string &palabra)
{
    Cronologia encontrados;
    Cronologia::iterator it;

    for (it = begin(); it != end(); it++)
    {
        FechaHistorica eventos = it->second.buscar_palabra_clave(palabra);
        if (!eventos.get_eventos().empty())
            encontrados.set_evento(eventos);
    }

    return encontrados;
}

Cronologia Cronologia::obtener_evento_rango(int inf, int sup)
{
    Cronologia rango;
    for (int i = inf; i <= sup; i++)
        if (existe_fecha(i))
            rango.set_evento(crono.at(i));

    return rango;
}

int Cronologia::size() const 
{
    return crono.size();
}

Cronologia Cronologia::operator+(const Cronologia &cronologia) const
{
    Cronologia suma(*this);

    for (Cronologia::const_iterator it = cronologia.cbegin();
         it != cronologia.cend(); it++)
        suma.set_evento(it->second);

    return suma;
}

istream &operator>>(istream &is, Cronologia &cronologia)
{
    while (!is.eof())
    {
        FechaHistorica entrada;
        is >> entrada;
        cronologia.set_evento(entrada);
    }

    return is;
}

ostream &operator<<(ostream &os, const Cronologia &c)
{
    Cronologia::const_iterator it;

    for (it = c.cbegin(); it != c.cend(); it++)
        os << it->second;

    return os;
}