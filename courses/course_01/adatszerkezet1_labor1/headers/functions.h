//
// Created by Dora on 2025. 02. 20..
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int osszead(int a, int b);
int szjo(int c, int osz);
float minimum(float number1, float number2, float number3);
float *allocateMemoryForArray(int n);
void allocateMemoryForArray2(int n, float **dpArray);
void deallocateMemoryForArray(float **dpArray);
void printArray(int n, float *pArray, const char *output);
void fillWithRandomNumbers(int n, float *pArray, float start, float end);
#endif //FUNCTIONS_H
