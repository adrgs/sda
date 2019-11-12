#ifndef COADA_H
#define COADA_H


template <typename T>
class Coada {
private:
    int inceput_coada;
    int sfarsit_coada;
    int dimensiune_coada;
    T* elemente;
public:
    Coada();
    Coada(int n);
    ~Coada();
    void push(T);
    T pop();
    T peek();
    T back();
    bool empty();
    int search(T);
    void afiseaza();
};

#endif // COADA_H
