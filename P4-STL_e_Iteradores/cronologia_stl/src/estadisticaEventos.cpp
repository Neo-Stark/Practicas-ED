#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    cout << "Dime el nombre del fichero con la cronologia" << endl;
    return 0;
  }

  ifstream f(argv[1]);
  if (!f)
  {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  int total_anios, total_acontecimientos = 0,
                   maximo = 0,
                   promedio = 0;
  Cronologia mi_cronologia;
  f >> mi_cronologia; //Cargamos en memoria, en el traductor.

  total_anios = mi_cronologia.size();

  Cronologia::const_iterator cit;
  for (cit = mi_cronologia.cbegin(); cit != mi_cronologia.cend(); cit++)
  {
    int aux = cit->second.numero_eventos();
    total_acontecimientos += aux;
    if (aux > maximo)
      maximo = aux;
  }
  promedio = total_acontecimientos / total_anios;

  cout  << "Número total de acontecimientos: " << total_acontecimientos << endl
        << "Total de años en los que hubo acontecimientos: "  << total_anios << endl
        << "Promedio de acontecimientos en esos años: " << promedio << endl
        << "Máximo de acontecimientos en un año: " << maximo << endl;
}