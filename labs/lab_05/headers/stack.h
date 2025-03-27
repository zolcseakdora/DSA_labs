//
// Created by Dora on 2025. 03. 20..
//

#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
typedef struct
{
    int capacity, top;
    int *elements;
}Stack_t;
void createStack(int capacity, Stack_t* stack);
void destroyStack(Stack_t* stack);
bool isFull(Stack_t stack);
bool isEmpty(Stack_t stack);
void push(Stack_t* stack, int item);
int pop(Stack_t* stack);
int peek(Stack_t stack);
int size(Stack_t stack);
int performOperation(int num1, int num2, char op);
bool isPalindrome(const char *text);
#endif //STACK_H
