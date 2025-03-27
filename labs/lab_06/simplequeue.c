//
// Created by Dora on 2025. 03. 27..
//

#include "simplequeue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void createQueue(int capacity, Simple_Queue_t* queue){
    queue->capacity=capacity;
    queue->rear=queue->front=-1;
    queue->elements=(char**)malloc(capacity*sizeof(char*));
    if (!queue->elements)
    {
        for (int i = 0; i < queue->capacity; ++i)
        {
            queue->elements[i]=(char*)malloc(capacity*sizeof(char));
            if (!queue->elements[i])
            {
                printf("Memory allocation error");
                exit(-2);
            }
        }
        printf("Memory allocation error");
        exit(-1);
    }
}

void destroyQueue(Simple_Queue_t* queue){
    for (int i = 0; i < queue->capacity; ++i)
    {
        free(queue->elements[i]);
    }
    free(queue->elements);
    queue->elements = NULL;
    queue->front = queue->rear = -1;
    queue->capacity = 0;
}

bool isFull(Simple_Queue_t queue){
    return queue.rear == queue.capacity - 1;
}

bool isEmpty(Simple_Queue_t queue) {
    return queue.front == -1;
}

void enqueue(Simple_Queue_t* queue, const char* item) {
    if (isFull(*queue)) {
        printf("The queue is full\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->elements[++queue->rear] = strdup(item);
}

int dequeue(Simple_Queue_t* queue) {
    if (isEmpty(*queue))
    {
        printf("The queue is empty");
        exit(-3);
    }
    int save=queue->elements[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear=-1;
    }
    else {
        queue->front++;
    }

    return save;
}

void display(Simple_Queue_t queue){
    if (isEmpty(queue)) {
        printf("The queue is empty");
        exit(-3);
    }
    for (int i=queue.front; i<=queue.rear; i++) {
        printf("%s ", queue.elements[i]);
    }
    printf("\n");
}

int peek(Simple_Queue_t queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
        exit(-3);
    }
    return queue.elements[queue.front];
}