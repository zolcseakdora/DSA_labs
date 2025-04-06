//
// Created by Dora on 2025. 04. 06..
//

#ifndef INTARRAY_H
#define INTARRAY_H
typedef struct {
    int capacity;
    int size;
    int *elements;
}IntArray_t;
void loadIntArrayFromFile(IntArray_t *pArray, const char *filename) ;
void createIntArray_t(int capacity, IntArray_t* pArray);
void printArray(IntArray_t array);
bool isFull(IntArray_t array);
bool isEmpty(IntArray_t array);
int getItemAt(IntArray_t array, int position);
void insertFirst(IntArray_t* pArray, int item);
void insertLast(IntArray_t* pArray, int item);
void insertAt(IntArray_t* pArray, int position, int item);
void deleteItemAt(IntArray_t* pArray, int position);
int search(IntArray_t pArray, int item);
bool update(IntArray_t* pArray, int position, int newItem);
void deallocateIntArray_t(IntArray_t *pArray);
#endif //INTARRAY_H
