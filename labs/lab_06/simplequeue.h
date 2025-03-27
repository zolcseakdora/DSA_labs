//
// Created by Dora on 2025. 03. 27..
//

#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H
#include <stdbool.h>
typedef struct {
    int capacity;
    int front;
    int rear;
    char **elements;
}Simple_Queue_t;

void createQueue(int capacity, Simple_Queue_t *queue);

void destroyQueue(Simple_Queue_t* queue);

bool isFull(Simple_Queue_t queue);

bool isEmpty(Simple_Queue_t queue);

void enqueue(Simple_Queue_t* queue, const char* item);

int dequeue(Simple_Queue_t* queue);

void display(Simple_Queue_t queue);

int peek(Simple_Queue_t queue);

#endif //SIMPLEQUEUE_H
