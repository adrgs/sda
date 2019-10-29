#include "Stiva.h"
#include <iostream>

template <typename T>
Stiva<T>::Stiva()
{
    elemente = new T[100];
    dimensiune_stiva = 100;
    nr_elemente = 0;
}
template <typename T>
Stiva<T>::Stiva(int n)
{
    if (n<1) n=100;
    elemente = new T[n];
    dimensiune_stiva = n;
    nr_elemente = 0;
}

template <typename T>
Stiva<T>::~Stiva()
{
    delete[] elemente;
    nr_elemente = 0;
}

template <typename T>
void Stiva<T>::push(T el)
{
    if (nr_elemente == dimensiune_stiva) {
        T *tmp = new T[2*dimensiune_stiva];
        for (int i=0;i<dimensiune_stiva;i++)
        {
            tmp[i] = elemente[i];
        }
        delete[] elemente;
        dimensiune_stiva = 2*dimensiune_stiva;
        elemente = tmp;
    }
    elemente[nr_elemente] = el;
    nr_elemente++;
}

template <typename T>
T Stiva<T>::pop()
{
    if (nr_elemente==0) throw "Stiva este goala";
    nr_elemente--;
    return elemente[nr_elemente];
}

template <typename T>
T Stiva<T>::peek()
{
    if (nr_elemente==0) throw "Stiva este goala";
    return elemente[nr_elemente-1];
}

template <typename T>
int Stiva<T>::search(T a)
{
    int dif = 0;
    for (int i=nr_elemente-1;i>=0;i--)
    {
        if (elemente[i] == a) return dif;
        dif++;
    }
    return -1;
}

template <typename T>
void Stiva<T>::afiseaza()
{
    for (int i=nr_elemente-1;i>=0;i--)
    {
        std::cout<<elemente[i]<<" ";
    }
    std::cout<<"\n";
}
