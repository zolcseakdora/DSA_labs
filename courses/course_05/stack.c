//
// Created by Dora on 2025. 04. 06..
//

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void loadStackFromFile(Stack_t *stack, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int item;
    while (fscanf(file, "%d", &item) != EOF) {
        push(stack, item);
    }

    fclose(file);
}
void createStack(int capacity, Stack_t *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int*)calloc(stack->capacity, sizeof (int));
    if(!stack->elements) {
        exit(-1);
    }
}
bool isEmpty(Stack_t  stack) {
    return stack.top == -1;
}
bool isFull(Stack_t  stack) {
    return stack.top == stack.capacity-1;
}
void push(Stack_t  *stack, int item) {
    if(isFull(*stack)) {
        return;
    }
    stack->elements[++stack->top] = item;
}
int pop(Stack_t  *stack) {
    if (isEmpty(*stack)) {
        return INT_MIN;
    }
    int save = stack->elements[stack->top];
    stack->elements[stack->top--] = 0;
    return save;
}
int peek(Stack_t  stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack.elements[stack.top];
}
int size(Stack_t  stack) {
    return stack.top+1;
}
void destroyStack(Stack_t* stack) {
    // Ellenőrizzük, hogy a verem nem NULL, és van-e hozzá rendelt memória.
    if (stack != NULL) {
        // Először a verem elemeinek memória felszabadítása
        free(stack->elements);
        stack->elements = NULL; // A pointert NULL-ra állítjuk biztonság kedvéért
        stack->capacity = 0;    // A verem kapacitását 0-ra állítjuk
        stack->top = -1;        // A tetejét is alaphelyzetbe állítjuk
    }
}
