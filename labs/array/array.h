//
// Created by dora on 4/3/2025.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum Szinek {
    RED,
    WHITE,
    BLACK,
    YELLOW,
    OTHER
}Szinek;


typedef struct {
    int atmero;
    Szinek szin;
    bool ala_irt;
}Labda;

typedef struct {
    int capacity;
    int size;
    Labda *elements;
}LabdaArray;

void createArray(int capacity, LabdaArray *pArray);
void printArray(LabdaArray array);
bool isFull(LabdaArray array);
bool isEmpty(LabdaArray array);
const char *getColorText(Szinek szin);
void readLabda(Labda *labda);
void insertFirst(LabdaArray *pArray, Labda labda);
void insertLast(LabdaArray *pArray, Labda labda);
void insertAt(LabdaArray *pArray, int index, Labda labda);
void readOsszesLabda(LabdaArray *pArray);
void printLabda(Labda labda);
void printOsszesLabda(LabdaArray *pArray);
void deallocateArray(LabdaArray *pArray);
Labda getItemAt(LabdaArray array, int position);
bool update(LabdaArray *pArray, int position, Labda newItem);
void labda_torol(LabdaArray *pArray);
int szamol_alairt(LabdaArray array);
int compare(const void *p1, const void *q1);
#endif //ARRAY_H
