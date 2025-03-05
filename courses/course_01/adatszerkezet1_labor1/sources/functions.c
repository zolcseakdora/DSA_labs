//
// Created by Dora on 2025. 02. 20..
//
#include <stdlib.h>
#include "functions.h"

#include <stdio.h>

int osszead(int a ,int b)
{
    return a+b;
}
int szjo(int c, int osz)
{
    osz=0;
    while (c!=0)
    {
       osz+=c%10;
        c/=10;
    }
    return osz;
}
int minimum(int number1, int number2, int number3)
{
    if (number1 <= number2 && number1 <= number3) {
        return number1;
    }
    if (number2 <= number1 && number2 <= number3) {
        return number2;
    }
    else
    {
        return number3;
    }
}
int *allocateMemoryForArray(int n)
{
    int *array=(int*)malloc(n*sizeof(int));
    if (!array)
    {
        exit(-1);
    }
    return array;
}
void allocateMemoryForArray2(int n,int **dpArray)
{
     *dpArray=(int*)malloc(n*sizeof(int));
    if (!*dpArray)
    {
        exit(-1);
    }
}
void deallocateMemoryForArray(int **dpArray)
{
    free(*dpArray);
    *dpArray=NULL;
}
void fillWithRandomNumbers(int n, int *pArray,int start, int end)
{
    for (int i=0; i<n; ++i)
    {
        pArray[i]=(end-start)*rand() +start;
    }
}
void printArray(int n, int *pArray, const char *output)
{
    FILE *out=fopen(output,"w");
    for (int i=0; i<n; i++)
    {
        fprintf(out,"%f ",pArray[i]);
    }
    fclose(out);
}