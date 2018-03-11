#include <iostream>
#include "Fecha_Historica.h"
#include <cassert>
using namespace std;

FechaHistorica::FechaHistorica(int fecha)
{
    set_fecha(fecha);
}

void FechaHistorica::copiar(const FechaHistorica &f)
{
    fecha.first = f.fecha.first;
    fecha.second = f.fecha.second; //Operador = sobrecargado de la clase set
}

FechaHistorica::FechaHistorica(const FechaHistorica &f)
{
    copiar(f);
}

void FechaHistorica::set_fecha(int fecha)
{
    this->fecha.first = fecha;
}

void FechaHistorica::aniade_evento(const string &evento)
{
    fecha.second.insert(evento);
}

void FechaHistorica::quita_evento()
{
    fecha.second.erase(*(fecha.second.rbegin()));
}

FechaHistorica FechaHistorica::buscar_palabra_clave(const string &palabra)
{
    FechaHistorica ocurrencias(this->get_fecha());
    FechaHistorica::const_iterator cit;
    for (cit = cbegin(); cit != cend(); cit++)
        if (cit->find(palabra) != string::npos)
            ocurrencias.aniade_evento(*cit);

    return ocurrencias;
}

int FechaHistorica::get_fecha() const
{
    return fecha.first;
}

string FechaHistorica::get_eventos() const
{
    string lista = "";
    set<string>::iterator it;
    for (it = cbegin(); it != cend(); it++)
        lista += '#' + *it;

    return lista;
}

int FechaHistorica::numero_eventos() const
{
    return fecha.second.size();
}

istream &operator>>(istream &is, FechaHistorica &fecha)
{
    string buffer, aux;

    size_t pos;

    getline(is, buffer, '\n');

    if (buffer.size() != 0)
    {
        //Extraer el anio
        pos = buffer.find('#');
        aux = buffer.substr(0, pos);
        fecha.set_fecha(stoi(aux));
        buffer.erase(0, ++pos);

        //Extraer los eventos
        while ((pos = buffer.find('#')) != string::npos)
        {
            aux = buffer.substr(0, pos);
            buffer.erase(0, ++pos);
            fecha.aniade_evento(aux);
        }
        if ((pos = buffer.find('\r')) != string::npos)
        {
            aux = buffer.substr(0, pos);
            buffer.erase(0, ++pos);
            fecha.aniade_evento(aux);
        }
        else
            fecha.aniade_evento(buffer);
    }

    return is;
}

ostream &operator<<(ostream &os, const FechaHistorica &fecha)
{
    os << fecha.get_fecha();
    os << fecha.get_eventos();
    os << '\n';

    return os;
}

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &fecha)
{
    if (this != &fecha)
        copiar(fecha);
    return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &fecha)
{
    assert(this->get_fecha() == fecha.get_fecha());
    FechaHistorica suma(*this);

    FechaHistorica::const_iterator cit;
    for (cit = fecha.cbegin(); cit != fecha.cend(); cit++)
        suma.aniade_evento(*cit);

    return suma;
}

FechaHistorica &FechaHistorica::operator+=(const FechaHistorica &fecha)
{
    return *this = *this + fecha;
}

bool FechaHistorica::operator<(const FechaHistorica &fecha)
{
    return this->get_fecha() < fecha.get_fecha();
}

bool FechaHistorica::operator>(const FechaHistorica &fecha)
{
    return this->get_fecha() > fecha.get_fecha();
}