#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class ListaSI
{
protected:
    typedef struct _nod
    {
        T val;
        struct _nod *urm;
    } nod;
    nod *prim;
    nod *ultim;
    int nr_elemente;

    nod *creare_element(T val)
    {
        nod *q = new nod;
        q->val = val;
        q->urm = NULL;
        return q;
    }
    void init()
    {
        prim = NULL;
        ultim = NULL;
        nr_elemente = 0;
    }

public:
    ListaSI()
    {
        init();
    };
    ~ListaSI()
    {
        stergere_lista();
    }
    int get_nr_elemente()
    {
        return nr_elemente;
    }
    void adaugare_final(T val)
    {
        if (ultim == NULL)
        {
            adaugare_inceput(val);
            return;
        }
        else
        {
            nod *tmp = creare_element(val);
            ultim->urm = tmp;
            ultim = tmp;
        }
        nr_elemente++;
    }
    void adaugare_inceput(T val)
    {
        nod *tmp = creare_element(val);
        if (prim == NULL)
            prim = tmp;
        else
        {
            tmp->urm = prim;
            prim = tmp;
        }
        if (ultim == NULL)
        {
            ultim = prim;
        }
        nr_elemente++;
    }
    void adaugare_la_pozitia(T val, int idx)
    {
        if (idx >= nr_elemente)
        {
            adaugare_final(val);
        }
        else if (idx < 1)
        {
            adaugare_inceput(val);
        }
        else
        {
            int i = 0;
            nod *p = prim;
            nod *q = creare_element(val);
            while (p != NULL)
            {
                if (i == idx - 1)
                {
                    q->urm = p->urm;
                    p->urm = q;
                    break;
                }
                p = p->urm;
                i++;
            }
            nr_elemente++;
        }
    }
    void afisare_lista()
    {
        nod *p = prim;
        int i = 0;
        std::cout << "Nr elemente:" << nr_elemente << " ";
        while (p != NULL)
        {
            std::cout << "|" << i << ":" << p->val << "|->";
            p = p->urm;
            i++;
        }
        std::cout << "NULL\n";
    }
    int cautare_dupa_valoare(T val)
    {
        nod *p = prim;
        int i = 0;
        while (p != NULL)
        {
            if (p->val == val)
                return i;
            p = p->urm;
            i++;
        }
        return -1;
    }
    T cautare_dupa_pozitie(int idx)
    {
        if (idx >= nr_elemente)
        {
            return ultim->val;
        }
        else if (idx < 1)
        {
            return prim->val;
        }
        else
        {
            nod *p = prim;
            int i = 0;
            while (p != NULL)
            {
                if (idx == i)
                    return p->val;
                p = p->urm;
                i++;
            }
        }
    }
    bool stergere_dupa_valoare(T val)
    {
        if (nr_elemente == 0)
            return false;
        bool sters = false;
        nod *p = prim;
        while (p != NULL)
        {
            if (p->urm != NULL && p->urm->val == val)
            {
                nod *tmp = p->urm;
                p->urm = tmp->urm;
                delete tmp;
                sters = true;
            }
            p = p->urm;
        }

        if (sters == true)
            nr_elemente--;
        return sters;
    }
    bool stergere_dupa_pozitie(int idx)
    {
        if (nr_elemente == 0)
            return false;

        if (idx < 1)
        {
            nod *tmp;
            tmp = prim;
            prim = prim->urm;
            delete tmp;
        }
        else if (idx >= nr_elemente)
        {
            nod *p = prim;
            while (p->urm->urm != NULL)
            {
                p = p->urm;
            }
            delete ultim;
            p->urm = NULL;
            ultim = p;
        }
        else
        {
            nod *p = prim;
            int i = 0;
            while (p != NULL)
            {
                if (idx - 1 == i)
                {
                    nod *tmp = p->urm;
                    p->urm = tmp->urm;
                    delete tmp;
                    break;
                }
                p = p->urm;
                i++;
            }
        }
        nr_elemente--;
        return true;
    }
    void stergere_lista()
    {
        nod *p = prim;
        while (p != NULL)
        {
            nod *tmp = p;
            p = tmp->urm;
            delete tmp;
            nod *p = prim;
        }
        init();
    }
    void adaugare_ordonat(T val)
    {
        if (prim == NULL || val <= prim->val)
        {
            adaugare_inceput(val);
        }
        else if (ultim == NULL || val >= ultim->val)
        {
            adaugare_final(val);
        }
        else
        {
            int i = 0;
            nod *p = prim;
            while (p != NULL)
            {
                if (val < p->val)
                {
                    adaugare_la_pozitia(val, i);
                    break;
                }
                p = p->urm;
                i++;
            }
        }
    }
};

void menu()
{
    ListaSI<int> lista;

    int optiune;
    int val;
    int poz;
    int idx_return;
    int v_return;
    while (true)
    {
        cout << "Selectati optiunea:\n1.Adaugare final\n2.Adaugare inceput\n3.Adaugare pe pozitie\n4.Afisarea listei\n5.Cautare dupa valoare\n6.Cautare dupa pozitie\n7.Stergere dupa valoare\n8.Stergere dupa pozitie\n9.Stergere lista\n10.Iesire\n";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "Valoare\n";
            cin >> val;
            lista.adaugare_final(val);
            break;
        case 2:
            cout << "Valoare\n";
            cin >> val;
            lista.adaugare_inceput(val);
            break;
        case 3:
            cout << "Valoare\n";
            cin >> val;
            cout << "Pozitie\n";
            cin >> poz;
            lista.adaugare_la_pozitia(val, poz);
            break;
        case 4:
            lista.afisare_lista();
            break;
        case 5:
        {
            cout << "Valoare\n";
            cin >> val;
            int idx_return = lista.cautare_dupa_valoare(val);
            if (idx_return == -1)
            {
                cout << "Nu a fost gasita valoarea\n";
            }
            else
            {
                cout << "Valoarea a fost gasita la pozitia " << idx_return << "\n";
            }
            break;
        }
        case 6:
        {
            cout << "Pozitie\n";
            cin >> poz;
            v_return = lista.cautare_dupa_pozitie(poz);
            cout << "La pozitia " << poz << " a fost gasita valoarea " << v_return << "\n";
            break;
        }
        case 7:
            cout << "Valoare\n";
            cin >> val;
            lista.stergere_dupa_valoare(val);
            break;
        case 8:
            cout << "Pozitie\n";
            cin >> poz;
            lista.stergere_dupa_pozitie(poz);
            break;
        case 9:
            lista.stergere_lista();
            break;
        case 10:
            return;
            break;
        }
    }
}

void lista_ordonata()
{
    ListaSI<int> lista;

    int val;
    while (true)
    {
        cin >> val;
        lista.adaugare_ordonat(val);
        lista.afisare_lista();
    }
}

template <typename T>
class ListaSI3 : public ListaSI<T>
{
public:
    int nr_elemente_pozitive()
    {
        int nr = 0;
        typename ListaSI<T>::nod *p = ListaSI<T>::prim;
        while (p != NULL)
        {
            if (p->val > 0)
                nr++;
            p = p->urm;
        }
        return nr;
    }
    double medie_nr_negative()
    {
        int nr = 0;
        int suma = 0;
        typename ListaSI<T>::nod *p = ListaSI<T>::prim;
        while (p != NULL)
        {
            if (p->val < 0)
            {
                suma += p->val;
                nr++;
            }
            p = p->urm;
        }
        if (nr == 0)
            return 0;
        return ((double)suma / nr);
    }
};

void problema3()
{
    ListaSI3<int> lista;
    int optiune;
    while (true)
    {
        cout << "1.Adaugare final\n2.Afisare lista\n3.Numarare elemente pozitive\n4.Medie aritmetica nr negative\n5.Iesire\n";
        cin >> optiune;
        int val;
        switch (optiune)
        {
        case 1:
            cin >> val;
            lista.adaugare_final(val);
            break;
        case 2:
            lista.afisare_lista();
            break;
        case 3:
            cout << "Exista " << lista.nr_elemente_pozitive() << " numere pozitive in lista\n";
            break;
        case 4:
            cout << "Media aritmetica a numerelor negative este " << lista.medie_nr_negative() << "\n";
            break;
        case 5:
            return;
            break;
        }
    }
}

template <typename T>
class ListaSI4 : public ListaSI<T>
{
public:
    void modifica_lista()
    {
        int idx = 0;
        typename ListaSI<T>::nod *p = ListaSI<T>::prim;
        while (p != NULL && p->urm != NULL)
        {
            double avg = (p->val + p->urm->val) / 2;
            ListaSI<T>::adaugare_la_pozitia(avg, idx + 1);
            idx += 2;
            p = p->urm->urm;
        }
    }
};

void problema4()
{
    ListaSI4<double> lista;
    int optiune;
    while (true)
    {
        cout << "1.Adaugare final\n2.Afisare lista\n3.Modifica lista\n4.Iesire\n";
        cin >> optiune;
        double val;
        switch (optiune)
        {
        case 1:
            cin >> val;
            lista.adaugare_final(val);
            break;
        case 2:
            lista.afisare_lista();
            break;
        case 3:
            lista.modifica_lista();
            break;
        case 4:
            return;
            break;
        }
    }
}

template <typename T>
class NumarMare : public ListaSI<T>
{
private:
    void afis_recursiv(typename ListaSI<T>::nod *p)
    {
        if (p == NULL)
            return;
        afis_recursiv(p->urm);
        cout << (char)(0x30 + p->val);
    }

public:
    void citeste_numar()
    {
        ListaSI<T>::stergere_lista();
        string tmp;
        cin >> tmp;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] <= '9' && tmp[i] >= '0')
                ListaSI<T>::adaugare_inceput(tmp[i] - 0x30);
            else
                break;
        }
    }
    void adauga_numar(NumarMare &nmare)
    {
        typename ListaSI<T>::nod *p = ListaSI<T>::prim;
        typename ListaSI<T>::nod *q = nmare.prim;
        int carry = 0;
        while (p != NULL && q != NULL)
        {
            char tmp = (p->val + q->val);
            p->val = (p->val + q->val + carry) % 10;
            carry = (tmp + carry) / 10;
            p = p->urm;
            q = q->urm;
        }
        while (p != NULL)
        {
            char tmp = p->val;
            p->val = (p->val + carry) % 10;
            carry = (tmp + carry) / 10;
            p = p->urm;
        }
        while (q != NULL)
        {
            char tmp = q->val;
            ListaSI<T>::adaugare_final((q->val + carry) % 10);
            carry = (tmp + carry) / 10;
            q = q->urm;
        }
        if (p == NULL && q == NULL && carry == 1)
        {
            ListaSI<T>::adaugare_final(1);
        }
    }
    void afisare_numar()
    {
        afis_recursiv(ListaSI<T>::prim);
    }
};

void problema5()
{
    NumarMare<char> nr1;
    NumarMare<char> nr2;
    int optiune;
    while (true)
    {
        cout << "1.Citeste nr1\n2.Citeste nr2\n3.Adauga nr1+nr2 in nr1\n4.Afisare numere\n5.Iesire\n";
        cin >> optiune;
        int val;
        switch (optiune)
        {
        case 1:
            nr1.citeste_numar();
            break;
        case 2:
            nr2.citeste_numar();
            break;
        case 3:
            nr1.adauga_numar(nr2);
            break;
        case 4:
            cout << "Nr1:";
            nr1.afisare_numar();
            cout << " Nr2:";
            nr2.afisare_numar();
            cout << "\n";
            break;
        case 5:
            return;
            break;
        }
    }
}

typedef struct _monom
{
    int grad;
    int coef;
} monom;

class Polinom : public ListaSI<monom>
{
public:
    void citeste_polinom()
    {
        while (true)
        {
            int g, c;
            cout << "Grad (Numar negativ pentru a iesi)\n";
            cin >> g;
            if (g < 0)
                return;
            cout << "Coeficient\n";
            cin >> c;
            if (c==0) continue;

            bool gasit = false;
            nod *p = prim;
            while (p != NULL)
            {
                if (g == p->val.grad)
                {
                    p->val.coef += c;
                    gasit = true;
                    break;
                }
                p = p->urm;
            }

            if (gasit == false)
            {
                monom tmp;
                tmp.grad = g;
                tmp.coef = c;
                adaugare_final(tmp);
            }
        }
    }
    void afisare_polinom()
    {
        nod *p = prim;
        while (p != NULL && p->urm != NULL)
        {
            cout << "(" << p->val.coef << ")*x^" << p->val.grad << "+";
            p = p->urm;
        }
        if (p != NULL)
        {
            cout << "(" << p->val.coef << ")*x^" << p->val.grad << "\n";
        }
    }
    double calculeaza_x(double x)
    {
        double suma = 0;
        nod *p = prim;
        while (p != NULL)
        {
            suma += p->val.coef * pow(x, p->val.grad);
            p = p->urm;
        }
        return suma;
    }
    void aduna_polinom(Polinom &pol)
    {
        nod *p = pol.prim;
        while (p != NULL)
        {
            nod *q = prim;
            bool gasit = false;
            while (q != NULL)
            {
                if (q->val.grad == p->val.grad)
                {
                    q->val.coef += p->val.coef;
                    gasit = true;
                }
                q = q->urm;
            }
            if (gasit == false)
                adaugare_final(p->val);
            p = p->urm;
        }
    }
};

void problema6()
{
    Polinom P;
    Polinom Q;
    int optiune;
    while (true)
    {
        cout << "1.Citeste P\n2.Citeste Q\n3.P(x)\n4.Q(x)\n5.Aduna Q in P\n6.Afisare polinoame\n7.Iesire\n";
        cin >> optiune;
        int val;
        double x;
        switch (optiune)
        {
        case 1:
            P.citeste_polinom();
            break;
        case 2:
            Q.citeste_polinom();
            break;
        case 3:
            cin >> x;
            cout << "P(" << x << ")=" << P.calculeaza_x(x) << "\n";
            break;
        case 4:
            cin >> x;
            cout << "Q(" << x << ")=" << Q.calculeaza_x(x) << "\n";
            break;
        case 5:
            P.aduna_polinom(Q);
            break;
        case 6:
            cout << "P(x)=";
            P.afisare_polinom();
            cout << "Q(x)=";
            Q.afisare_polinom();
            break;
        case 7:
            return;
            break;
        }
    }
}

int main()
{
    //menu();
    //lista_ordonata();
    problema3();
    problema4();
    problema5();
    problema6();
    return 0;
}
