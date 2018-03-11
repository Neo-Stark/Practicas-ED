#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream &operator<<(ostream &s, const set<T> &c)
{

  typename set<T>::const_iterator i;

  for (i = c.begin(); i != c.end(); i++)
    s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla()
{
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max)
{
  int tam = max - min + 1;
  return ((rand() % tam) + min);
}

set<int> Union(const set<int> &b, const set<int> &c)
{
  set<int> a;
  auto itb = b.cbegin();
  auto itc = c.cbegin();
  for (itb; itb != b.cend(); itb++)
    a.insert(*itb);
  for (itc; itc != c.cend(); itc++)
    a.insert(*itc);

  return a;
}

set<int> DifSimetrica(const set<int> &b, const set<int> &c)
{
  set<int> a;
  auto itb = b.cbegin();
  auto itc = c.cbegin();

  for (itb; itb != b.cend(); itb++)
    if (c.find(*itb) == c.end())
      a.insert(*itb);

  for (itc; itc != c.cend(); itc++)
    if (b.find(*itc) == b.end())
      a.insert(*itc);

  return a;
}

set<int> nMayores(const set<int> &b, const set<int> &c, unsigned n)
{
  set<int> u = Union(b, c);
  set<int> a;
  auto rita = u.rbegin();

  for (rita; a.size() != n; rita++)
    a.insert(*rita);
  return a;
}

int main()
{

  set<int> c;
  set<int> b;

  InicializarSemilla();

  for (int i = 0; i < 10; i++)
    c.insert(generaEntero(1, 100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout << endl
       << c;

  for (int i = 0; i < 10; i++)
    b.insert(generaEntero(1, 100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout << endl
       << b;

  cout << endl
       << Union(b, c);
  cout << endl
       << DifSimetrica(b, c);
  cout << endl
       << nMayores(b, c, 5);
}
