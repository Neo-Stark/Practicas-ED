#include <iostream>
#include "Fecha_historica.h"
#include <vector>
#include <cassert>
using namespace std;

FechaHistorica::FechaHistorica(int fecha)
{
    set_fecha(fecha);
}

void FechaHistorica::copiar(const FechaHistorica &f)
{
    fecha = f.fecha;
    eventos = f.eventos; //Operador = sobrecargado de la clase vector
}

FechaHistorica::FechaHistorica(const FechaHistorica &f)
{
    copia(f);
}

void FechaHistorica::set_fecha(int fecha)
{
    this->fecha = fecha;
}

void FechaHistorica::push_back(const string &evento)
{
    eventos.push_back(evento);
}

void FechaHistorica::pop_back()
{
    eventos.pop_back();
}

FechaHistorica FechaHistorica::buscar_palabra_clave(const string &palabra)
{
    FechaHistorica ocurrencias(this->get_fecha);
    for (unsigned i = 0; i < eventos.size(); ++i)
        if (eventos.at(i).find(palabra) != string::npos)
            ocurrencias.eventos.push_back(eventos.at(i));

    return ocurrencias;
}

int FechaHistorica::get_fecha()
{
    return fecha;
}

string FechaHistorica::get_eventos()
{
    string lista = "";
    vector<string>::iterator it;
    for (it = eventos.begin(); it < eventos.end(); it++)
        lista += '#' + *it + '\n';

    return lista;
}
istream &operator>>(istream &is, FechaHistorica &fecha)
{
    string evento = "";
    getline(is, fecha.fecha, '#');
    while (!is.eof())
    {
        getline(is, evento, '#');
        fecha.eventos.push_back(evento);
    }

    return is;
}

ostream &operator<<(ostream &os, const FechaHistorica &fecha)
{
    vector<string>::iterator it;
    os << fecha.get_fecha();
    for (it = fecha.eventos.begin(); it < fecha.eventos.end(); it++)
        os << '#' << *it;
    os << '\n';

    return os;
}

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &fecha)
{
    if (this != &fecha)
        copia(fecha);
    return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &fecha)
{
    assert(this->get_fecha() == fecha.get_fecha());
    FechaHistorica suma(*this);

    vector<string>::iterator it;
    for (it = fecha.eventos.begin(); it < fecha.eventos.end(); it++)
        suma.eventos.push_back(it);

    return suma;
}

FechaHistorica &FechaHistorica::operator+=(const FechaHistorica &fecha)
{
    return *this = *this + fecha;
}

bool FechaHistorica::operator<(const FechaHistorica &fecha)
{
    return this->get_fecha() < fecha.get_fecha() ? true : false;
}

bool FechaHistorica::operator>(const FechaHistorica &fecha)
{
    return !get_fecha < fecha.get_fecha();
}