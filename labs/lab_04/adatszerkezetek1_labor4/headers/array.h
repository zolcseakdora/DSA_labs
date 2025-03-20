//
// Created by Dora on 2025. 03. 13..
//

#ifndef ARRAY_H
#define ARRAY_H
#define DEFAULT_VALUE (-1)
typedef struct {
    int capacity;
    int size;
    int *elements;
}IntArray;
/*
 * Product DEFAULT_PRODUCT={" "," "}
 * return DEFAULT_PRODUCT
 */
void createIntArray(int capacity, IntArray* pArray);
void printArray(IntArray array);
bool isFull(IntArray array);
bool isEmpty(IntArray array);
int getItemAt(IntArray array, int position);
void insertFirst(IntArray* pArray, int item);
void insertLast(IntArray* pArray, int item);
void insertAt(IntArray* pArray, int position, int item);
void deleteItemAt(IntArray* pArray, int position);
int search(IntArray pArray, int item);
bool update(IntArray* pArray, int position, int newItem);
void deallocateIntArray(IntArray *pArray);
#endif //ARRAY_H
