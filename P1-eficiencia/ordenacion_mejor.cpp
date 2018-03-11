#include <iostream>
#include <ctime>   // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
using namespace std;

int buscar(const int *v, int n, int x)
{
    int i = 0;
    while (i < n && v[i] != x)
        i = i + 1;
    if (i < n)
        return i;
    else
        return -1;
}

void burbuja(int *v, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
}

void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
    if (argc != 3) // Lectura de parámetros
        sintaxis();
    int tam = atoi(argv[1]);  // Tamaño del vector
    int vmax = atoi(argv[2]); // Valor máximo
    if (tam <= 0 || vmax <= 0)
        sintaxis();

    // Generación del vector aleatorio

    int *v = new int[tam];        // Reserva de memoria 
    for (int i = 0; i < tam; i++) // Recorrer vector
        v[i] = i;   

    clock_t tini; // Anotamos el tiempo de inicio
    tini = clock();
    burbuja(v, tam);
    clock_t tfin; // Anotamos el tiempo de finalización
    tfin = clock();

    // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
    cout << tam << "\t" << (tfin - tini) / (double)CLOCKS_PER_SEC << endl;
    delete[] v; // Liberamos memoria dinámica
}