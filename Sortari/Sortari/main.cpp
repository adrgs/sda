#include <iostream>
#include <stdio.h>
#include <assert.h>

int swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void clasic_sort(int *tablou, int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (tablou[j]<tablou[i])
            {
                swap(tablou + i,tablou + j);
            }
        }
    }
}

void bubble_sort(int *tablou, int n)
{
    bool sortat=false;

    while(sortat==false) {
        sortat = true;
        for (int i=0;i<n-1;i++)
        {
            if (tablou[i+1]<tablou[i]) {
                sortat = false;
                swap(tablou + i, tablou+i+1);
            }
        }
    }
}

void selection_sort(int *tablou, int n)
{
    for (int i=0;i<n-1;i++)
    {
        int minim_index = i;

        for (int j=i+1;j<n;j++)
        {
            if (tablou[j] < tablou[minim_index])
            {
                minim_index = j;
            }
        }

        if (minim_index!=i)
            swap(tablou+i, tablou+minim_index);
    }
}

void insertion_sort(int *tablou, int n)
{
    for (int i=1;i<n;i++)
    {
        int val = tablou[i];
        int j=i-1;
        for (;j>=0 && val < tablou[j]; j--)
        {
            tablou[j+1] = tablou[j];
        }
        tablou[j+1] = val;
    }
}

void test_sortare(int *tablou1, int *tablou2, int n)
{
    for (int i=0;i<n;i++)
    {
        assert(tablou1[i]==tablou2[i]);
    }
    printf("OK\n");
}
//insertion sort, selection sort, bubble sort

int main()
{
    int tablou_1[10] = {6, 5, 2, 8, 9, 1, 10, 13, 14, 11};
    int tablou_2[10] = {6, 5, 2, 8, 9, 1, 10, 13, 14, 11};
    int tablou_3[10] = {6, 5, 2, 8, 9, 1, 10, 13, 14, 11};
    int tablou_control[10] = {6, 5, 2, 8, 9, 1, 10, 13, 14, 11};
    int n=10;

    bubble_sort(tablou_1, n);
    selection_sort(tablou_2, n);
    insertion_sort(tablou_3, n);
    clasic_sort(tablou_control, n);

    for (int i=0;i<n;i++)
    {
        printf("%d ", tablou_3[i]);
    }
    printf("\n");

    test_sortare(tablou_1, tablou_control, n);
    test_sortare(tablou_2, tablou_control, n);
    test_sortare(tablou_3, tablou_control, n);

    return 0;
}
