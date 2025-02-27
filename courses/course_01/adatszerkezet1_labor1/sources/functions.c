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
float minimum(float number1, float number2, float number3)
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
float *allocateMemoryForArray(int n)
{
    float *array=(float*)malloc(n*sizeof(float));
    if (!array)
    {
        exit(-1);
    }
    return array;
}
void allocateMemoryForArray2(int n, float **dpArray)
{
     *dpArray=(float*)malloc(n*sizeof(float));
    if (!*dpArray)
    {
        exit(-1);
    }
}
void deallocateMemoryForArray(float **dpArray)
{
    free(*dpArray);
    *dpArray=NULL;
}
void fillWithRandomNumbers(int n, float *pArray, float start, float end)
{
    for (int i=0; i<n; ++i)
    {
        pArray[i]=(end-start)*(float)rand() / RAND_MAX +start;
    }
}
void printArray(int n, float *pArray, const char *output)
{
    FILE *out=fopen(output,"w");
    for (int i=0; i<n; i++)
    {
        fprintf(out,"%f ",pArray[i]);
    }
    fclose(out);
}