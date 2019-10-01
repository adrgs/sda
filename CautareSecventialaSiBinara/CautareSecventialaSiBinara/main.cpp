#include <fstream>
#include <assert.h>

using namespace std;

int cautare_secventiala(int *tablou, int n, int val)
{
    for (int i=0;i<n;i++)
    {
        if (tablou[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int cautare_binara(int *tablou, int l, int r, int val)
{
    if (l<=r)
    {
        int m = (r-l)/2 + l;
        if (tablou[m] == val) return m;

        if (val < tablou[m]) return cautare_binara(tablou, l, m-1, val);
        else
        {
            return cautare_binara(tablou, m+1, r, val);
        }
    }

    return -1;
}

int main()
{
    int tablou[10] = {6, 5, 2, 8, 9, 1, 10, 13, 14, 11};
    int tablou_ordonat[10] = {2, 4, 6, 9, 11, 22, 34, 35, 40, 41};
    int n=10;

    for (int i=0;i<n;i++)
    {
        assert(i == cautare_secventiala(tablou, 10, tablou[i]));
        assert(i == cautare_binara(tablou_ordonat, 0, 9, tablou_ordonat[i]));
    }

    return 0;
}
