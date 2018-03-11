#include <iostream>
#include "pila_max.h"

using namespace std;
int main()
{
    Pila_max p;
    // for (i = 0; i < 10; i++)
    for (int i = 10; i >= 0; i--)
        p.push(i);
    while (!p.empty())
    {
        elemento x = p.top();
        cout << x << endl;
        p.pop();
    }
    return 0;
}