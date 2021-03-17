#include <stdio.h>
#include <stdlib.h>

/* método com subproblema n/2 */ 
int Metodo1(int a[], int l, int r)
{
    if (r - l == 1)
        return a[l];
    int m = (l + r) / 2;
    int u = Metodo1(a, l, m);
    int v = Metodo1(a, m, r);
    return u > v ? u : v;
}

/* metodo com suproblema n-1 */

int Metodo2(int a[], int n, int maior)
{

    if (n == 0)
    {
        return maior;
    }

    if (a[n] > maior)
    {
        maior = a[n];
        Metodo2(a, n - 1, maior);
    }

    else
    {
        Metodo2(a, n - 1, maior);
    }
}

int main()

{
    int a[] = {5, 8, 40, 30, 20, 40, 50, 10, 17, 51};
    int b[] = {5, 8, 40, 30, 20, 40, 50, 10, 17, 51};
    int n = sizeof(a) / sizeof(int);
    int n1 = sizeof(b) / sizeof(int);
    int maior = 0;
    printf("Subproblema n/2: %d\n",Metodo1(a, 0, n));
    printf("Subproblema n-1: %d\n", Metodo2(b, n1, maior));

    return 0;
}