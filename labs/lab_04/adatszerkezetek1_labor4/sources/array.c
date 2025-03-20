//
// Created by Dora on 2025. 03. 13..
//

#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void createIntArray(int capacity, IntArray* pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (int*)malloc(capacity * sizeof(int));
}
void printArray(IntArray array) {
    if (isEmpty(array)) {
        printf("Array is empty.\n");
    } else {
        for (int i = 0; i < array.size; i++) {
            printf("%d ", array.elements[i]);
        }
        printf("\n");
    }
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
int getItemAt(IntArray array, int position)
{
    if (position >= 0 && position < array.size) {
        return array.elements[position];
    }
    return 0;
}
void insertFirst(IntArray* pArray, int item)
{
    if (isFull(*pArray)){return;}
    for (int i = pArray->size; i >= 0; i--)
    {
     pArray->elements[i]=pArray->elements[i-1];
    }
    pArray->elements[0]=item;
    pArray->size++;
}
void insertLast(IntArray* pArray, int item)
{
    if (isFull(*pArray)){return;}
    pArray->elements[pArray->size]=item;
    pArray->size++;
}
void insertAt(IntArray* pArray, int position, int item)
{
    if (isFull(*pArray)){return;}
    for (int i = pArray->size; i >= position; i--)
    {
        pArray->elements[i]=pArray->elements[i-1];
    }
    pArray->elements[position]=item;
    pArray->size++;
}
void deleteItemAt(IntArray* pArray, int position)
{
    if (position < 0 || position >= pArray->size) return;

    for (int i = position; i < pArray->size - 1; i++) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->size--;
}
int search(IntArray pArray, int item) {
    for (int i = 0; i < pArray.size; i++) {
        if (pArray.elements[i] == item) {
            return i;
        }
    }
    return -1;
}
bool update(IntArray* pArray, int position, int newItem) {
    if (position >= 0 && position < pArray->size) {
        pArray->elements[position] = newItem;
        return true;
    }
    return false;
}
void deallocateIntArray(IntArray *pArray) {
    free(pArray->elements);
    pArray->elements = NULL;
    pArray->capacity = 0;
    pArray->size = 0;
}
