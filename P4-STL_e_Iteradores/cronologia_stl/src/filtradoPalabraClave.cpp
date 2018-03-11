#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 4 && argc != 3 && argc != 2)
    {
        cout << "Uso: " << argv[0] << " fichEntrada" << endl;
        cout << "[OPCIONAL]: palabra clave a buscar";
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
    Cronologia rango;
    f >> mi_cronologia; //Cargamos en memoria, en el traductor.
    if (argc == 2)
    {
        string pal;
        cout << "Dime una palabra a consultar:";
        cin >> pal;

        rango = mi_cronologia.buscar_palabra_clave(pal);
    }
    else
        rango = mi_cronologia.buscar_palabra_clave(argv[2]);

    if (argc == 3 || argc == 2) //No se dio fichero de salida, imprimimos en cout
        cout << rango;
    else
    {
        ofstream fout(argv[3]);
        if (!fout)
        {
            cout << "No puedo crear el fichero " << argv[3] << endl;
            return 0;
        }
        fout << rango;
    }
}