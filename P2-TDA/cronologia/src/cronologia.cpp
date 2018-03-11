#include <iostream>
#include "cronologia.h"

using namespace std;

void Cronologia::copia(const Cronologia &crono)
{
    vector<string>::iterator it;
    for (it = crono.crono.begin(); it < crono.crono.end(); it++)
        this->crono.push_back(*it);
}

Cronologia::Cronologia(const Cronologia &crono)
{
    copia(crono);
}

bool Cronologia::existe_fecha(int fecha)
{
    bool existe = false;
    vector<string>::iterator it;

    for (it = crono.begin(); it < crono.end(); it++)
        if (it->fecha == fecha)
            existe = true;

    return existe;
}

FechaHistorica &Cronologia::obtener_fecha(int fecha)
{
    vector<string>::iterator it;

    for (it = crono.begin(); it < crono.end(); it++)
        if (it->fecha == fecha)
            return *it;
}

void Cronologia::set_evento(const FechaHistorica &fecha)
{
    if (existe_fecha(fecha.get_fecha()))
        obtener_fecha(fecha.get_fecha()) += fecha;
    else
    {
        crono.push_back(fecha);
        ordenar();
    }
}

void Cronologia::ordenar()
{
    vector<FechaHistorica>::iterator it;
    for (unsigned i = 0; i < crono.size(); i++)
    {
        int max = crono.at(i).get_fecha();
        for (it = crono.begin() + i; it != crono.end; it++)
            if (it->get_fecha() > max)
            {
                FechaHistorica aux(*it);
                *it = crono.at(i);
                crono.at(i) = aux;
            }
    }
}

Cronologia Cronologia::buscar_palabra_clave(const string &palabra)
{
    Cronologia encontrados;
    vector<FechaHistorica>::iterator it = crono.begin();

    for (it; it != crono.end(); it++)
        encontrados.set_evento(it->buscar_palabra_clave(palabra))

            return encontrados;
}

Cronologia Cronologia::obtener_evento_rango(int inf, int sup)
{
    Cronologia rango;
    for (int i = inf; i <= sup; i++)
        if (existe_fecha(i))
            rango.crono.push_back(crono.at(i));

    return rango;
}

Cronologia Cronologia::operator+(const Cronologia &cronologia)
{
    Cronologia suma(*this);

    for (vector<FechaHistorica>::iterator it = crono.begin();
         it != crono.end(); it++)
        suma.set_evento(*it);

    return suma;
}

istream &operator>>(istream &is, Cronologia &cronologia)
{
    FechaHistorica entrada;
    while (!is.eof())
    {
        is >> entrada;
        cronologia.set_evento(entrada);
    }

    return is;
}

ostream &operator<<(ostream &os, const Cronologia &cronologia)
{
    vector<FechaHistorica>::iterator it = crono.begin();

    for (it; it != crono.end(); it++)
        os << *it;

    return os;
}