#include <iostream>
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

void problema5()
{
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

int main()
{
    //menu_coada();
    //menu_stiva();
    //problema2();
    //problema3();
    problema5();
    return 0;
}
