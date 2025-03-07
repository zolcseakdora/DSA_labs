#include <stdio.h>
#include "functions.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    /*
     int a, b,osz,c;
    scanf("%i%i%i", &a,&b,&c);
    int s=osszead(a,b);
    int p=szjo(c,osz);
    printf("%i\n", s);
    printf("%i", p);
    */
    //tomb feldolgozas
    srand(time(NULL));
    int n; int *arr;
    do {
        scanf("%d", &n);
    } while (n <= 0 || n % 2 == 0);
    //foglald le
    //arr = allocateMemoryForArray(n);
    allocateMemoryForArray2(n,&arr);
    //toltsd fel
    int start=0, end=1;
    fillWithRandomNumbers( n,arr,start,end);
    // ird ki
    printArray(n, arr,"result.txt");
    //keress minimumot
    int elso=arr[0];
    int kozep=arr[n/2];
    int utolso=arr[n-1];
    int min=minimum(elso,kozep,utolso);
    if (min == elso)
        printf("Az elso elem a kisebb: %f\n", elso);
    else if (min== kozep)
        printf("A kozepso elem a kisebb: %f\n", kozep);
    else
        printf("Az utolso elem a kisebb: %f\n", utolso);
    // szabaditsd fel
    deallocateMemoryForArray(&arr);
    return 0;
}
