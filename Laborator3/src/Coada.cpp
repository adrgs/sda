#include "Coada.h"
#include <iostream>

template <typename T>
Coada<T>::Coada()
{
    elemente = new T[100];
    dimensiune_coada = 100;
    inceput_coada = 0;
    sfarsit_coada = 0;
}
template <typename T>
Coada<T>::Coada(int n)
{
    if (n<1) n=100;
    elemente = new T[n];
    dimensiune_coada = n;
    inceput_coada = 0;
    sfarsit_coada = 0;
}

template <typename T>
Coada<T>::~Coada()
{
    delete[] elemente;
    inceput_coada = 0;
    sfarsit_coada = 0;
}

template <typename T>
void Coada<T>::push(T el)
{
    if (inceput_coada - sfarsit_coada == dimensiune_coada-1) {
        T *tmp = new T[2*dimensiune_coada];
        for (int i=0;i<dimensiune_coada;i++)
        {
            tmp[i] = elemente[(i+inceput_coada)%dimensiune_coada];
        }
        delete[] elemente;
        sfarsit_coada = dimensiune_coada;
        dimensiune_coada = 2*dimensiune_coada;
        elemente = tmp;
    }
    elemente[sfarsit_coada] = el;
    sfarsit_coada++;
}

template <typename T>
T Coada<T>::pop()
{
    if (inceput_coada == sfarsit_coada) throw "Coada este goala";
    T tmp = elemente[inceput_coada];
    inceput_coada = (inceput_coada+1)%dimensiune_coada;
    return tmp;
}

template <typename T>
T Coada<T>::peek()
{
    if (inceput_coada == sfarsit_coada) throw "Coada este goala";
    return elemente[inceput_coada];
}

template <typename T>
int Coada<T>::search(T a)
{
    //int dif = 0;
    //for (int i=nr_elemente-1;i>=0;i--)
    //{
    //    if (elemente[i] == a) return dif;
    //    dif++;
    //}
    return -1;
}

template <typename T>
void Coada<T>::afiseaza()
{
    for (int i=inceput_coada;i<sfarsit_coada;i=(i+1)%dimensiune_coada)
    {
        std::cout<<elemente[i]<<" ";
    }
    std::cout<<"\n";
}
