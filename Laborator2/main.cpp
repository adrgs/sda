#include <iostream>

using namespace std;

template <typename T>
class ListaSI
{
private:
    typedef struct _nod {
        T val;
        struct _nod* urm;
    } nod;
    nod* prim;
    nod* ultim;
    int nr_elemente;

    nod* creare_element(T val)
    {
        nod* q = new nod;
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
    ListaSI() {
        init();
    };
    ~ListaSI()
    {
        stergere_lista();
    }
    void adaugare_final(T val) {
        if (ultim == NULL)
        {
            adaugare_inceput(val);
            return;
        } else{
            nod *tmp = creare_element(val);
            ultim->urm = tmp;
            ultim = tmp;
        }
        nr_elemente++;
    }
    void adaugare_inceput(T val) {
        nod *tmp  = creare_element(val);
        if (prim == NULL) prim = tmp;
        else {
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
        if (idx >= nr_elemente) {
            adaugare_final(val);
        }
        else if (idx < 1)        {
            adaugare_inceput(val);
        }
        else {
            int i=0;
            nod* p = prim;
            nod* q = creare_element(val);
            while (p!=NULL)
            {
                if (i==idx-1)
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
        nod* p = prim;
        int i = 0;
        std::cout<<"Nr elemente:"<<nr_elemente<<" ";
        while (p!=NULL)
        {
            std::cout<<"|"<<i<<":"<<p->val<<"|->";
            p = p->urm;
            i++;
        }
        std::cout<<"NULL\n";
    }
    int cautare_dupa_valoare(T val)
    {
        nod* p = prim;
        int i = 0;
        while (p!=NULL)
        {
            if (p->val == val) return i;
            p = p->urm;
            i++;
        }
        return -1;
    }
    T cautare_dupa_pozitie(int idx)
    {
        if (idx >= nr_elemente) {
            return ultim->val;
        }
        else if (idx < 1) {
            return prim->val;
        } else {
            nod* p = prim;
            int i=0;
            while (p!=NULL)
            {
                if (idx==i) return p->val;
                p = p->urm;
                i++;
            }
        }
    }
    bool stergere_dupa_valoare(T val)
    {
        if (nr_elemente==0) return false;
        bool sters = false;
        nod* p = prim;
        while (p != NULL)
        {
            if (p->urm != NULL && p->urm->val == val)
            {
                nod* tmp = p->urm;
                p->urm = tmp->urm;
                delete tmp;
                sters = true;
            }
            p = p->urm;
        }

        if (sters == true) nr_elemente--;
        return sters;
    }
    bool stergere_dupa_pozitie(int idx)
    {
        if (nr_elemente==0) return false;

        if (idx < 1) {
            nod* tmp;
            tmp = prim;
            prim = prim->urm;
            delete tmp;
        }
        else if (idx >= nr_elemente) {
            nod* p = prim;
            while (p->urm->urm != NULL)
            {
                p = p->urm;
            }
            delete ultim;
            p->urm = NULL;
            ultim = p;
        } else {
            nod* p = prim;
            int i=0;
            while (p!=NULL)
            {
                if (idx-1==i)
                {
                    nod* tmp = p->urm;
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
        nod* p = prim;
        while (p!=NULL)
        {
            nod *tmp = p;
            p = tmp->urm;
            delete tmp;nod* p = prim;
        }
        init();
    }
    void adaugare_ordonat(T val)
    {
        if (prim == NULL || val <= prim->val) {
            adaugare_inceput(val);
        }
        else if (ultim == NULL || val >= ultim->val)
        {
            adaugare_final(val);
        } else {
            int i=0;
            nod *p = prim;
            while (p!=NULL)
            {
                if (val < p->val)
                {
                    adaugare_la_pozitia(val, i);
                    break;
                }
                p=p->urm;
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
        cout<<"Selectati optiunea:\n1.Adaugare final\n2.Adaugare inceput\n3.Adaugare pe pozitie\n4.Afisarea listei\n5.Cautare dupa valoare\n6.Cautare dupa pozitie\n7.Stergere dupa valoare\n8.Stergere dupa pozitie\n9.Stergere lista\n10.Iesire\n";
        cin>>optiune;
        switch(optiune)
        {
        case 1:
            cout<<"Valoare\n";cin>>val;
            lista.adaugare_final(val);
            break;
        case 2:
            cout<<"Valoare\n";cin>>val;
            lista.adaugare_inceput(val);
            break;
        case 3:
            cout<<"Valoare\n";cin>>val;
            cout<<"Pozitie\n";cin>>poz;
            lista.adaugare_la_pozitia(val, poz);
            break;
        case 4:
            lista.afisare_lista();
            break;
        case 5:
            {
            cout<<"Valoare\n";cin>>val;
            int idx_return = lista.cautare_dupa_valoare(val);
            if (idx_return==-1)
            {
                cout<<"Nu a fost gasita valoarea\n";
            }
            else {
                cout<<"Valoarea a fost gasita la pozitia "<<idx_return<<"\n";
            }
            break;
            }
        case 6:
            {
            cout<<"Pozitie\n";cin>>poz;
            v_return = lista.cautare_dupa_pozitie(poz);
            cout<<"La pozitia "<<poz<<" a fost gasita valoarea "<<v_return<<"\n";
            break;
            }
        case 7:
            cout<<"Valoare\n";cin>>val;
            lista.stergere_dupa_valoare(val);
            break;
        case 8:
            cout<<"Pozitie\n";cin>>poz;
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
    while (true) {
        cin>>val;
        lista.adaugare_ordonat(val);
        lista.afisare_lista();
    }
}

int main()
{
    menu();
    lista_ordonata();
    return 0;
}
