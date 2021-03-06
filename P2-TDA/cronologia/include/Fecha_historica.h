/**
 * @file Fecha_historica.h
 * @brief fichero de cabecera del TDA Fecha_Historica
 * 
 * Se crea un contenedor para almacenar acontecimientos ocurridos en un año
 */
#ifdef __FECHAHISTORICA
#define __FECHAHISTORICA

#include <iostream>
#include <string>
#include <vector>

using namespace std;

    /**
    * @brief TDA Fecha Historica
    * 
    * Una instancia @e c del TDA @c Fecha_Historica es un objeto
    * que almacena acontecimientos ocurridos a lo largo de un año.
    * Está compuesto por un valor entero que representa el año y
    * un vector de string para representar los diferentes acontecimientos
    * Lo representamos:
    * fecha#evento#evento...
    */

class FechaHistorica
{
  private:
    /**
    * @page repConjunto Rep del TDA Fecha_Historica
    *
    * @section invConjunto Invariante de la representación
    *
    * Para fechas anteriores al año 0 se utilizarán enteros negativos
    * Cada evento debe incluir # como primer caracter
    *
    * @section faConjunto Función de abstracción
    *
    * Un objeto válido @e rep del TDA Fecha_Historica representa al objeto
    *
    * rep.fecha#rep.eventos[0]#rep.eventos[n-1]
    *
    */
    int fecha /**< fecha */;

    vector<string> eventos /**< eventos */;


    /**
     * @brief copia una Fecha historica en la instancia actual
     * @param f instancia de FechaHistorica a copiar
     */
    void copia(const FechaHistorica& f);

  public:
    /**
     * @Brief Constructor de la clase
     * @param fecha año de la FechaHistorica a construir, por defecto 0
     * @return crea una instancia de FechaHistorica
     */ 
    FechaHistorica(int fecha = 0);

    /** 
     * @Brief Constructor de copia
     * @param f.fecha año de la fecha histórica a construir
     * @param f.eventos eventos de la fecha histórica a construir
     * @return crea una copia de la fecha histórica f
     */
    FechaHistorica(const FechaHistorica &f);

    /**
     * @Brief push_back
     * @param evento evento a insertar
     * Añade un evento al final del vector
    */
    void push_back(const string& evento);

    /**
     * @brief establece la fecha
     * @param fecha año de los eventos
     */
    void set_fecha(int fecha);

    /**
     * @Brief pop_back
     * Elimina el último evento del objeto
     */
    void pop_back();

    /**
     * @Brief buscar_palabra_clave
     * @param palabra recibe una palabra de tipo string
     * @return devuelve un string con todas las ocurrencias encontradas
     * Dada una palabra busca todas las ocurrencias dentro de la fecha histórica
     * y devuelve un string con todas ellas.
     */
    string buscar_palabra_clave(const string& palabra);

    /**
     * @brief get_fecha
     * @return devuelve el año de la fecha histórica
     */
    int get_fecha();

    /**
    * @brief Entrada de una FechaHistorica desde istream
    * @param is stream de entrada
    * @param fecha FechaHistorica que recibe el valor
    */
    friend istream& operator>> (istream& is, FechaHistorica& fecha);

    /**
    * @brief Salida de una FechaHistorica a ostream
    * @param os stream de salida
    * @param fecha FechaHistorica a escribir
    * @post Se obtiene en \a os la cadena fecha#evento#evento[..] con \e fecha,evento los valores
    *   de fecha y eventos de \a FechaHistorica
    */
    friend ostream& operator<< (ostream& os, const FechaHistorica& fecha);

    /**
     * @brief concatenación de Fechas Historicas
     * @pre Deben ser las mismas fechas
     * @param fecha FechaHistorica que concatenar
     * @return La concatenación del objeto implicito y fecha
     */
    FechaHistorica operator+(const FechaHistorica &fecha);

    /**
     * @brief asignación de fechas históricas
     * @param fecha FechaHistorica a copiar
     * @return referencia al objeto FechaHistorica
     */
    FechaHistorica& operator=(const FechaHistorica& fecha);

    /**
     * @brief concatenación y asignación de FechaHistorica objeto con otra fecha
     * @param fecha FechaHistorica que concatenar
     * @return referencia al objeto ya concatenado
     */
    FechaHistorica operator+=(const FechaHistorica& fecha);

    /**
     * @brief comparación de fechas
     * @param fecha FechaHistorica a comparar
     * @return devuelve true si la fecha del objeto receptor
     * es menor a la del objeto fecha, false en otro caso
     */
    bool operator < (const FechaHistorica& fecha);

    /**
     * @brief comparación de fechas
     * @param fecha FechaHistorica a comparar
     * @return devuelve true si la fecha del objeto receptor
     * es mayor a la del objeto fecha, false en otro caso
     */
    bool operator > (const FechaHistorica& fecha);

};

#endif 