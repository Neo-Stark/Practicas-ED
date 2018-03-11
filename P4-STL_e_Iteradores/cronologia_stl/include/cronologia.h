/**
 * @file cronologia.h
 * @brief fichero de cabecera del TDA Cronologia
 * 
 * Se crea un contenedor para almacenar acontecimientos ocurridos a lo largo de la historia
 */
#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <map>
#include "Fecha_Historica.h"

using namespace std;
/**
     * @brief TDA cronologia
     * 
     * Una instancia @e c del TDA @c cronologia es un objeto
     * que almacena acontecimientos ocurridos a lo largo de la historia.
     * Está compuesto por un contenedor map de la stl que tiene como clave
     * el año de cada acontecimiento y como valor un objeto de FechaHistórica que contiene cada uno 
     * de los eventos ocurridos a lo largo del tiempo.
     * 
     * Ejemplo de uso:
     * @include src/pruebacronologia.cpp
     */

class Cronologia
{
private:
  /**
    * @page repConjunto Rep del TDA Cronologia
    *
    * @section invConjunto Invariante de la representación
    *
    * Para fechas anteriores al año 0 se utilizarán enteros negativos
    * Cada evento debe incluir # como primer caracter
    * No puede haber dos fechas históricas con el mismo año
    *
    * @section faConjunto Función de abstracción
    *
    * Un objeto válido @e rep del TDA Cronologia con @e n tamaño representa al objeto
    *
    * 
    * rep[0].first#rep[0].second[0]#rep[0].second[t-1]
    * rep[1].first#rep[1].second[0]#rep[1].second[t-1]
    * rep[n-1].first#rep[n-1].second[0]#rep[n-1].second[t-1]
    *
    */
  map<int, FechaHistorica> crono; /**< map de fechas historicas*/

  /**
     * @brief copia una cronologia en la instancia actual
     * @param crono instancia de Cronologia a copiar
     */
  void copia(const Cronologia &crono);

public:
  /**
     * @brief constructor de la clase
     * @return crea una instancia de cronologia sin ningún elemento
     */
  Cronologia(){};
  
  /** 
     * @brief constructor de copia
     * @param fecha[n].first año de los eventos
     * @param fecha[n].second eventos ocurridos en esa fecha
     */
  Cronologia(const Cronologia &fecha);

  /**
     * @brief comprueba una fecha
     * @param fecha año a comprobar
     * @return devuelve true si la FechaHistorica fecha existe en la cronología
     */
  bool existe_fecha(int fecha);

  /**
     * @brief obtener una fecha histórica de la cronología
     * @param fecha año a buscar
     * @return devuelve la FechaHistorica asociada a fecha
     * Si la fecha no está en la cronología, crea una entrada vacía para esa fecha
     */
  FechaHistorica &obtener_fecha(int fecha);

  /**
     * @brief añadir evento
     * @param evento evento a incluir
     * añade un evento (o conjunto de ellos) a la cronología
     */
  void set_evento(const FechaHistorica &evento);

  /**
     * @brief busqueda por palabra clave
     * @param palabra palabra a buscar
     * @return devuelve una cronología con todas las ocurrencias
     */
  Cronologia buscar_palabra_clave(const string &palabra);

  /**
     * @brief obtener evento en un rango
     * @param inf año inferior del rango
     * @param inf año superior del rango
     * @return Devuelve una cronología con los eventos 
     *          dentro del rango, ambos extremos incluidos
     */
  Cronologia obtener_evento_rango(int inf, int sup);

  /**
     * @brief Total de años
     * @return numero de años con eventos
     * Devuelve un contador del total de número de años para los que existen eventos en la cronología
     */
  int size() const;

  /**
     * @brief Union de dos cronologías
     * @param cronologia cronología a concatenar
     * @return Devuelve la concatenación del objeto
     *          receptor y el parámetro cronologia
     */
  Cronologia operator+(const Cronologia &cronologia) const;

  /**
   * @brief Sobrecarga del operator []
   * @param d Año de la posición a devolver
   * @return FechaHistorica con el año d
   */
  FechaHistorica &operator[](int anio) { return crono[anio]; }

  /**
    * @brief Entrada de una Cronologia desde istream
    * @param is stream de entrada
    * @param cronologia Cronologia que recibe el valor
    */
  friend istream &operator>>(istream &is, Cronologia &cronologia);

  /**
     * @brief Salida de una Cronologia a ostream
     * @param os stream de salida
     * @param cronologia Cronologia a escribir
     * @post Se obtiene en \a os la cadena fecha#evento#evento[..]\n fecha#evento#evento[..]
     *  con \e fecha,evento los valores de fecha y eventos de \a FechaHistorica dentro de Cronologia
     */
  friend ostream &operator<<(ostream &os, const Cronologia &cronologia);

  /*************************ITERADORES**********************************/

  typedef typename map<int, FechaHistorica>::iterator iterator;
  typedef typename map<int, FechaHistorica>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del map
   * @return Iterador señalando al primer elemento
   */
  iterator begin() { return crono.begin(); }

  /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const { return crono.cbegin(); }

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  iterator end() { return crono.end(); }

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const { return crono.cend(); }
};
#endif /*__CRONOLOGIA*/