#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 4 && argc != 5)
    {
        cout << "Uso: " << argv[0] << " fichEntrada min max" << endl;
        cout << "[OPCIONAL]: un segundo fichero para guardar la cronologia resultante";
        return 0;
    }

    ifstream f(argv[1]);
    if (!f)
    {
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }

    Cronologia mi_cronologia;
    f >> mi_cronologia; //Cargamos en memoria, en el traductor.

    Cronologia rango;
    int min = atoi(argv[2]),
        max = atoi(argv[3]);
    rango = mi_cronologia.obtener_evento_rango(min, max);
    if (argc == 4)                                        //No se dio fichero de salida, imprimimos en cout
        cout << rango;
    else
    {
        ofstream fout(argv[4]);
        if (!fout)
        {
            cout << "No puedo crear el fichero " << argv[4] << endl;
            return 0;
        }
        fout << rango;
    }
}