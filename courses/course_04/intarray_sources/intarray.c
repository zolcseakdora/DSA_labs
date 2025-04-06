//
// Created by Dora on 2025. 04. 06..
//

#include "../intarray_headers/intarray.h"

#include <stdio.h>
#include <stdlib.h>
void loadIntArrayFromFile(IntArray_t *pArray, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int item;
    while (fscanf(file, "%d", &item) != EOF) {
        insertLast(pArray, item);  // Hozzáadjuk a tömbhöz az adatokat
    }

    fclose(file);
}
//Üres-e a tömb, tele-e a tömb
bool isFull(IntArray_t array) {
    return array.size == array.capacity;
}
bool isEmpty(IntArray_t array) {
    return array.size == 0;
}
//Tömb struktúra mezőinek inicializálása,helyfoglalás
void createIntArray_t(int capacity, IntArray_t *pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements =(int*) calloc(capacity,sizeof(int));
    if (!pArray->elements) {
        exit(-1);
    }
}
//Tömb elemeinek kiíratása
void printArray(IntArray_t array){
    if (isEmpty(array)) {
        return;
    }
    printf("The elements of the array: ");
    for (int i = 0; i < array.size; ++i) {
        printf("%i ", array.elements[i]);
    }
    printf("\n");
}
//Új elem bevitele az első pozícióra
void insertFirst(IntArray_t* pArray, int item) {
    if (isFull(*pArray)) return;
    //shifting the rest of the elements downwards
    for (int i = pArray->size-1; i >= 0; --i) {
        pArray->elements[i+1] = pArray->elements[i];
    }
    pArray->elements[0] = item;
    pArray->size++;
}
//Új elem bevitele az utolsó pozícióra
void insertLast(IntArray_t* pArray, int item) {
    if (isFull(*pArray)) return;
    pArray->elements[pArray->size++] = item;
}
//Új elem bevitele egy adott pozícióra
void insertAt(IntArray_t* pArray, int position, int item) {
    if (isFull(*pArray)) return;
    if(position < 0 || position > pArray->size) {return;}
    if(pArray->size == position) {
        insertLast(pArray, item);return;}
    if(position == 0) {
        insertFirst(pArray, item);return;}
    for (int i = pArray->size-1; i >= position; --i) {
        pArray->elements[i+1] = pArray->elements[i];
    }
    pArray->elements[position] = item; pArray->size++;
}
//Adott pozíciójú elem törlése
void deleteItemAt(IntArray_t *pArray, int position) {
    if(isEmpty(*pArray)) {return;}
    if ((position < 0 || position >= pArray->size)) {
        return;
    }
    for (int i = position; i < pArray->size; ++i) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->size--;
}
//Adott értékű elem keresése (első előfordulásának pozíciója)
int search(IntArray_t pArray, int item) {
    if(isEmpty(pArray)) {
        return -1;}
    for (int i = 0; i < pArray.size; ++i) {
        if(pArray.elements[i] == item) return i;
    }
    return -1;
}
//Adott értékű elem módosítása
bool update(IntArray_t *pArray, int position, int newItem)
{
    if(isEmpty(*pArray)) {
        return false;}
    if ((position < 0 || position >= pArray->size)) {
        return false;
    }
    pArray->elements[position] = newItem;
    return true;
}
//Adott pozíciójú elem visszatérítése
int getItemAt(IntArray_t array, int position) {
    if(isEmpty(array)) { return false;}
    if ((position < 0 || position >= array.size)) {
        return INT_MIN;
    }
    return array.elements[position];
}
//Helyfelszabaditas
void deallocateIntArray_t(IntArray_t *pArray) {
    free(pArray->elements);
    pArray->elements = NULL;
    pArray = NULL;
}
