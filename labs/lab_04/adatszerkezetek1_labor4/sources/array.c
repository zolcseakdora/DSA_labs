//
// Created by Dora on 2025. 03. 13..
//

#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void createIntArray(int capacity, IntArray* pArray)
{
    pArray = (IntArray*)malloc(capacity*sizeof(IntArray));
    if (!pArray)
    {
        exit(-1);
    }
}
void printArray(IntArray array)
{
    printf("Kapacitas: %i\n",array.capacity);
    printf("Meret: %i\n",array.size);
    printf("Elemek: %i\n",array.elements);
}
bool isFull(IntArray array)
{
    if (array.capacity==array.size)
    {
        return true;
    }
    return false;
}
bool isEmpty(IntArray array)
{
    if (array.size==0)
    {
        return true;
    }
    return false;
}
void deallocateIntArray(IntArray *pArray)
{
    free(pArray);
}