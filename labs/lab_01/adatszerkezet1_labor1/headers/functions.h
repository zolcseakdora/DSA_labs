//
// Created by Dora on 2025. 02. 20..
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int osszead(int a, int b);
int szjo(int c, int osz);
int minimum(int number1, int number2, int number3);
int *allocateMemoryForArray(int n);
void allocateMemoryForArray2(int n, int **dpArray);
void deallocateMemoryForArray(int **dpArray);
void printArray(int n, int *pArray, const char *output);
void fillWithRandomNumbers(int n, int *pArray, int start, int end);
#endif //FUNCTIONS_H
