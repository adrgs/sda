#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Stiva.h"
#include "Stiva.cpp"
#include "Coada.h"
#include "Coada.cpp"

using namespace std;

void menu_stiva()
{
    Stiva<int> stiva;
    while (true)
    {
        try {
            cout<<"===Menu Stiva===\n1.Push\n2.Pop\n3.Peek\n4.Empty\n5.Search\n6.Afiseaza\n7.Exit\n";
            int op;
            cin>>op;
            int x;
            int result = -1;
            switch (op)
            {
                case 1:
                cin>>x;
                stiva.push(x);
                cout<<"Am adaugat valoarea "<<x<<" pe stiva\n";
                break;
                case 2:
                cout<<"Am scos valoarea: "<<stiva.pop()<<" de pe stiva\n";
                break;
                case 3:
                cout<<"Ultima valoare pe stiva este:"<<stiva.peek()<<"\n";
                break;
                case 4:
                if (stiva.empty()) {
                    cout<<"Stiva este goala\n";
                } else {
                    cout<<"Stiva nu este goala\n";
                }
                break;
                case 5:
                cin>>x;
                result = stiva.search(x);
                if (result == -1) cout<<"Elementul dat nu a fost gasit in lista\n";
                else {
                    cout<<"Elementul dat a fost gasit pe pozitia: "<<result<<"\n";
                }
                break;
                case 6:
                stiva.afiseaza();
                break;
                case 7:
                return;
                break;
            }
        }
        catch (const char *eroare)
        {
            cout<<eroare<<"\n";
        }
    }
}

void menu_coada()
{
    Coada<int> coada;
    while (true)
    {
        try {
            cout<<"===Menu Coada===\n1.Push\n2.Pop\n3.Peek\n4.Empty\n5.Search\n6.Afiseaza\n7.Exit\n";
            int op;
            cin>>op;
            int x;
            int result = -1;
            switch (op)
            {
                case 1:
                cin>>x;
                coada.push(x);
                cout<<"Am adaugat valoarea "<<x<<" pe coada\n";
                break;
                case 2:
                cout<<"Am scos valoarea: "<<coada.pop()<<" de pe coada\n";
                break;
                case 3:
                cout<<"Ultima valoare pe coada este:"<<coada.peek()<<"\n";
                break;
                case 4:
                if (coada.empty()) {
                    cout<<"coada este goala\n";
                } else {
                    cout<<"coada nu este goala\n";
                }
                break;
                case 5:
                cin>>x;
                result = coada.search(x);
                if (result == -1) cout<<"Elementul dat nu a fost gasit in lista\n";
                else {
                    cout<<"Elementul dat a fost gasit pe pozitia: "<<result<<"\n";
                }
                break;
                case 6:
                coada.afiseaza();
                break;
                case 7:
                return;
                break;
            }
        }
        catch (const char *eroare)
        {
            cout<<eroare<<"\n";
        }
    }
}

void problema2()
{
    cout<<"===Problema 2===\n";
    string s;
    getline(cin, s);
    Stiva<char> stiva;
    for (char c:s)
    {
        if (c!='a' && c!='b') continue;
        if (stiva.empty())
        {
            stiva.push(c);
        } else {
            if (stiva.peek()!=c)
            {
                stiva.pop();
            } else {
                stiva.push(c);
            }
        }
    }
    if (stiva.empty())
    {
        cout<<"Exista un numar egal de a si b in string-ul dat\n";
    } else {
        cout<<"Numarul de a si b difera in string-ul dat\n";
    }
}

void problema3()
{
    cout<<"===Problema 3===\n";
    string s;
    getline(cin, s);
    Stiva<char> stiva;
    int i=-1;
    for (char c:s)
    {
        i++;
        if (c!='(' && c!=')') continue;
        if (stiva.empty())
        {
            if (c=='(') stiva.push(c);
            else {
                cout<<"Sirul nu este parantezat corect, ) de la pozitia "<<i<<" este pus gresit\n";
                return;
            }
        } else {
            if (c!=stiva.peek()) {
                stiva.pop();
            } else {
                stiva.push(c);
            }
        }
    }
    if (stiva.empty())
    {
        cout<<"Sirul dat este parantezat corect!\n";
    }
    else {
        cout<<"Sirul dat NU este parantezat corect!\n";
    }
}

void problema4()
{
    cout<<"===Problema 4===\n";
    int n;
    cin>>n;
    Stiva<int> stiva;
    if (n%2==1) {
        cout<<"Exista un pin fara pereche!\n";
        return;
    }
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (stiva.empty()) {
            stiva.push(x);
        } else {
            if (stiva.peek() == x) {
                stiva.pop();
            } else {
                stiva.push(x);
            }
        }
    }
    if (stiva.empty()) {
        cout<<"Configuratia data este valida!\n";
    } else {
        cout<<"Configuratia data NU este valida!\n";
    }
}

void problema5()
{
    cout<<"===Problema 5===\n";
    string s;
    getline(cin, s);
    Stiva<int> stiva;
    istringstream iss(s);
    string tmp;
    while (getline(iss, tmp, ' '))
    {
        unsigned int len = tmp.length();
        if (len<0) continue; 
        if (len==1)
        {
            if (tmp[0]>='0' && tmp[9]<='9')
            {
                stiva.push((int)tmp[0]-'0');
            } else {
                try {
                    int b = stiva.pop();
                    int a = stiva.pop();
                    int c = 0;
                    switch (tmp[0])
                    {
                    case '+':
                        c = a+b;
                        break;
                    case '-':
                        c = a-b;
                        break;
                    case '*':
                        c = a*b;
                        break;
                    case '/':
                        c = a/b;
                        break;
                    case '%':
                        c = a%b;
                        break;
                    }
                    stiva.push(c);
                } catch(const char* eroare)
                {
                    cout<<"Eroare, expresia este invalida!\n";
                    return;
                } catch(...)
                {
                    cout<<"Eroare impartire/modulo 0\n";
                    return;
                }
            }
        }
        else {
            int a = stoi(tmp);
            stiva.push(a);
        }
    }
    if (stiva.empty())
    {
        cout<<"Eroare, expresia este invalida!\n";
    } else {
        int rez = stiva.pop();
        if (!stiva.empty()) {
            cout<<"Eroare, expresia este invalida!\n";
        } else {
            cout<<"Rezultatul expresiei este "<<rez<<"\n";
        }
    }
}

void problema7()
{
    cout<<"===Problema 7===\n";
    ifstream fin("prob7.txt");
    int m;
    fin>>m;
    int mat[m][m];
    
    for (int i=0;i<m;i++)
            for (int j=0;j<m;j++)
                fin>>mat[i][j];

    typedef struct _coord {
        int i,j;
    }coord;

    Coada<coord> coada;
    int newval=2;

    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
        {
            if (mat[i][j]!=1) continue;
            coada.push(coord {i,j});
            mat[i][j]=newval;
            while (!coada.empty())
            {
                coord tmp = coada.pop();
                if (tmp.i-1>=0 && mat[tmp.i-1][tmp.j]==1) {
                    mat[tmp.i-1][tmp.j] = newval;
                    coada.push(coord {tmp.i-1,tmp.j});
                }
                if (tmp.i+1<m && mat[tmp.i+1][tmp.j]==1) {
                    mat[tmp.i+1][tmp.j] = newval;
                    coada.push(coord {tmp.i+1,tmp.j});
                }
                if (tmp.j-1>=0 && mat[tmp.i][tmp.j-1]==1)
                {
                    mat[tmp.i][tmp.j-1] = newval;
                    coada.push(coord {tmp.i,tmp.j-1});
                }
                if (tmp.j+1<m && mat[tmp.i][tmp.j+1]==1)
                {
                    mat[tmp.i][tmp.j+1] = newval;
                    coada.push(coord {tmp.i,tmp.j+1});
                }
            }
            newval++;
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
}

void problema8()
{
    cout<<"===Problema 8===\n";
    //k = 3
    //n = 9
    //v = 5 8 1 7 4 2 9 6 3
    int k,n;
    cout<<"k=";cin>>k;
    Coada<int> *cozi = new Coada<int>[k];
    cout<<"n=";cin>>n;
    int v[n];
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int val_max = n;
    for (int i=0;i<n;i++)
    {
        int linie_goala=-1;
        int min_coada=0x7fffffff;
        int min_linie = -1;
        for (int j=0;j<k;j++)
        {
            if (cozi[j].empty()) {
                linie_goala=j;
                break;
            }
            if (cozi[j].peek()<min_coada && cozi[j].back() > v[i]) {
                min_coada = cozi[j].peek();
                min_linie = j;
            }
        }
        if (min_linie!=-1) {
            cout<<"Inseram vagonul "<<v[i]<<" pe linia "<<min_linie<<"\n";
            cozi[min_linie].push(v[i]);
        } else {
            if (linie_goala!=-1) {
                cout<<"Inseram vagonul "<<v[i]<<" pe linia "<<linie_goala<<"\n";
                cozi[linie_goala].push(v[i]);
            } else {
                cout<<"Din pacate vagoanele nu pot fi ordonate\n";
                delete[] cozi;
                return;
            }
        }
        for (int j=0;j<k;j++)
        {
            cozi[j].afiseaza();
        }
        for (int j=0;j<k;j++)
        {
            if (cozi[j].empty()) continue;
            if (cozi[j].peek()==val_max) {
                cout<<"Scoatem vagonul "<<cozi[j].peek()<<" de pe linia "<<j<<"\n";
                val_max--;
                cozi[j].pop();
                j=-1;
            }
        }
    }
    cout<<"Vagoanele au fost aranjate in ordinea buna!\n";
    delete[] cozi;
}

typedef struct _nod {
    int val;
    struct _nod* next;
} nod;

void problema9()
{
    cout<<"===Problema 9===\n";
    int n;
    cout<<"A n=";cin>>n;
    nod* A = NULL;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nod* tmp = new nod;
        tmp->val = x;
        tmp->next = A;
        A = tmp;
    }
    cout<<"Lista A\n";
        for (nod *p=A;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    nod* B = NULL;
    for (nod *p=A;p!=NULL;p=p->next)
    {
        nod* tmp = new nod;
        tmp->val=p->val;
        tmp->next = B;
        B = tmp;
    }
    cout<<"Lista B\n";
    for (nod *p=B;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    cout<<"Lista A\n";
        for (nod *p=A;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    nod *p = NULL;
    nod *lastp = NULL;
    for (p=A;p!=NULL;)
    {
        nod *urm = p->next;
        if (urm == NULL) {
            A = p;
        }
        p->next = lastp;
        lastp = p;
        p=urm;
    }
    cout<<"Lista A\n";
        for (nod *p=A;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
}

void problema10()
{
    cout<<"===Problema 10===\n";
    int n;
    cout<<"A n=";cin>>n;
    nod* A = NULL;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nod* tmp = new nod;
        tmp->val = x;
        tmp->next = A;
        A = tmp;
    }
    cout<<"B n=";cin>>n;
    nod* B = NULL;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nod* tmp = new nod;
        tmp->val = x;
        tmp->next = B;
        B = tmp;
    }
    cout<<"Lista B\n";
    for (nod *p=B;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    cout<<"Lista A\n";
        for (nod *p=A;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    nod *C = NULL;
    nod *lastC = NULL;
    while (A != NULL || B!=NULL)
    {
        if (C==NULL)
        {
            if (A->val < B->val)
            {
                C = A;
                A = A->next;
            } else {
                C = B;
                B = B->next;
            }
            lastC = C;
        }
        if (A==NULL) {
            lastC->next = B;
            B = B->next;
        } else if (B==NULL) {
            lastC->next = A;
            A = A->next;
        } else {
            if (A->val < B->val) {
                lastC->next = A;
                A = A->next;
            } else {
                lastC->next = B;
                B = B->next;
            }
        }
        lastC = lastC->next;
    }
    for (nod *p=C;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
}

void problema11()
{
    cout<<"===Problema 11===\n";
    int n;
    cout<<"n=";cin>>n;
    nod* C = NULL;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nod* tmp = new nod;
        tmp->val = x;
        tmp->next = C;
        C = tmp;
    }
    for (nod *p=C;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";

    nod *A = NULL;
    nod *B = NULL;

    int i = 0;

    for (nod *p=C;p!=NULL;)
    {
        nod *urm = p->next;
        if (i%2==0) {
            if (B==NULL) {
                B = p;
                if (B->next!=NULL)
                    B->next = B->next->next;
                else {
                    B->next = NULL;
                }
            } else {
                if (p->next != NULL) {
                    p->next = p->next->next;
                }
            }
        } else {
            if (A==NULL) {
                A = p;
                if (A->next!=NULL)
                    A->next = A->next->next;
                else {
                    A->next = NULL;
                }
            } else {
                if (p->next != NULL) {
                    p->next = p->next->next;
                }
            }
        }
        i++;
        p=urm;
    }
    cout<<"Lista B\n";
    for (nod *p=B;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
    cout<<"Lista A\n";
        for (nod *p=A;p!=NULL;p=p->next)
    {
        cout<<p->val<<" ";
    }
    cout<<"\n";
}

int main()
{
    //menu_coada();
    //menu_stiva();
    //problema2();
    //problema3();
    //problema4();
    //problema5();
    //problema7();
    //problema8();
    problema9();
    //problema10();
    //problema11();
    return 0;
}
