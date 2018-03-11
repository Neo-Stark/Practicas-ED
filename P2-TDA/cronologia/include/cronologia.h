 /**
 * @file cronologia.h
 * @brief fichero de cabecera del TDA Cronologia
 * 
 * Se crea un contenedor para almacenar acontecimientos ocurridos a lo largo de la historia
 */
#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include "Fecha_historica.h"

using namespace std;
     /**
     * @brief TDA cronologia
     * 
     * Una instancia @e c del TDA @c cronologia es un objeto
     * que almacena acontecimientos ocurridos a lo largo de la historia.
     * Está compuesto por un vector de Fecha_Histórica que contiene cada uno 
     * de los eventos ocurridos a lo largo del tiempo.
     * 
     * Ejemplo de uso:
     * @include pruebacronologia.cpp
     */

class Cronologia{
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
    * rep[0].fecha#rep[0].eventos[0]#rep[0].eventos[t-1]
    * rep[1].fecha#rep[1].eventos[0]#rep[1].eventos[t-1]
    * rep[n-1].fecha#rep[n-1].eventos[0]#rep[n-1].eventos[t-1]
    *
    */
    vector<FechaHistorica> crono; /**< vector de fechas historicas*/

    /**
     * @brief copia una cronologia en la instancia actual
     * @param crono instancia de Cronologia a copiar
     */
    void copia(const Cronologia& crono);
public:
    /**
     * @brief constructor de la clase
     * @return crea una instancia de cronologia sin ningún elemento
     */
    Cronologia();
    /** 
     * @brief constructor de copia
     * @param fecha[n].fecha año de los eventos
     * @param fecha[n].eventos eventos ocurridos en esa fecha
     */
    Cronologia(const Cronologia& fecha);
    /**
     * @brief comprueba una fecha
     * @param fecha año a comprobar
     * @return devuelve true si la FechaHistorica fecha existe en la cronología
     */
    bool existe_fecha(int fecha);
    /**
     * @brief obtener una fecha histórica de la cronología
     * @param fecha año a buscar
     * @pre la fecha debe estar en la cronología
     * @return devuelve la FechaHistorica asociada a fecha
     */
    FechaHistorica& obtener_fecha(int fecha);
    /**
     * @brief añadir evento
     * @param evento evento a incluir
     * añade un evento (o conjunto de ellos) a la cronología
     */
    void set_evento(const FechaHistorica& evento);
    /**
     * @brief ordenar
     * ordena la cronología según el año
     */
    void ordenar();
    /**
     * @brief busqueda por palabra clave
     * @param palabra palabra a buscar
     * @return devuelve una cronología con todas las ocurrencias
     */
    Cronologia buscar_palabra_clave(const string& palabra);
    /**
     * @brief obtener evento en un rango
     * @param inf año inferior del rango
     * @param inf año superior del rango
     * @return Devuelve una cronología con los eventos 
     *          dentro del rango, ambos extremos incluidos
     */
    Cronologia obtener_evento_rango(int inf, int sup);
    /**
     * @brief Concatena dos cronologías
     * @param cronologia cronología a concatenar 
     * @return Devuelve la concatenación del objeto
     *          receptor y el parámetro cronologia
     */
    Cronologia operator+(const Cronologia& cronologia);
    /**
    * @brief Entrada de una Cronologia desde istream
    * @param is stream de entrada
    * @param cronologia Cronologia que recibe el valor
    * @retval El Racional leído en cronologia
    */
    friend istream& operator>>(istream& is, Cronologia& cronologia);
    /**
     * @brief Salida de una Cronologia a ostream
     * @param os stream de salida
     * @param cronologia Cronologia a escribir
     * @post Se obtiene en \a os la cadena fecha#evento#evento[..]\n fecha#evento#evento[..]
     *  con \e fecha,evento los valores de fecha y eventos de \a FechaHistorica dentro de Cronologia
     */
    friend ostream& operator<<(ostream& os, const Cronologia& cronologia);

}
#endif