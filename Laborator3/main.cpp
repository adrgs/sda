#include <iostream>
#include "Stiva.h"
#include "src/Stiva.cpp"
#include "Coada.h"
#include "src/Coada.cpp"

using namespace std;

int main()
{
    Stiva<char> stiva;
    stiva.push('e');
    stiva.push('o');
    stiva.push('j');
    stiva.afiseaza();

    Coada<char> coada;
    coada.push('j');
    coada.push('o');
    coada.push('e');

    coada.pop();
    coada.pop();
    coada.pop();
    coada.pop();
    coada.afiseaza();
    return 0;
}
