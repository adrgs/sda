#ifndef STIVA_H
#define STIVA_H


template <typename T>
class Stiva {
private:
    int nr_elemente;
    int dimensiune_stiva;
    T* elemente;
public:
    Stiva();
    Stiva(int n);
    ~Stiva();
    void push(T);
    T pop();
    T peek();
    bool empty();
    int search(T);
    void afiseaza();
};

#endif // STIVA_H
