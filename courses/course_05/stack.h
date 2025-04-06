//
// Created by Dora on 2025. 04. 06..
//

#ifndef STACK_H
#define STACK_H
typedef struct
{
    int capacity, top;
    int *elements;
}Stack_t;
void loadStackFromFile(Stack_t *stack, const char *filename);
/**
* Initializing the capacity and size of stack,
* allocating memory for the @elements array
* @param capacity
* @param stack
*/
void createStack(int capacity, Stack_t* stack);
/**
* Deallocates the memory
* @param stack
*/
void destroyStack(Stack_t* stack);
/**
* Checks whether the stack is full
* @param stack
* @return
*/
bool isFull(Stack_t stack);
/**
* Checks whether the stack is empty
* @param stack
* @return
*/
bool isEmpty(Stack_t stack);
/**
* Pushes a new item to the stack,
* if it is not full
* @param stack
* @param item
*/
void push(Stack_t* stack, int item);
/**
* Removes the top element from the stack,
* if it is not empty
* @param stack
* @return
*/
int pop(Stack_t* stack);
/**
* Returns the top element of the stack,
* if it is not empty
* @param stack
* @return
*/
int peek(Stack_t stack);
/**
* Returns the size of the stack
* @param stack
* @return
*/
int size(Stack_t stack);
#endif //STACK_H
