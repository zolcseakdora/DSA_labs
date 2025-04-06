//
// Created by Dora on 2025. 04. 06..
//

#include "../circle_queue_h/circle_queue.h"

#include <stdio.h>
#include <stdlib.h>

void loadCircleQueueFromFile(CircularQueue_t *queue, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int item;
    while (fscanf(file, "%d", &item) != EOF) {
        enqueueCircle(queue, item);
    }

    fclose(file);
}
void createCircleQueue(int capacity, CircularQueue_t *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (int*) malloc(capacity * sizeof(int));
    if (!queue->elements) {
        exit(-1);  // Memory allocation failed
    }
}

void destroyCircleQueue(CircularQueue_t *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->front = queue->rear = -1;
}
bool isFullCircle(CircularQueue_t queue)
{
    return (queue.front-1==queue.rear || (queue.front==0 &&
   queue.rear==queue.capacity-1));
}
bool isEmptyCircle(CircularQueue_t queue)
{
    return queue.front==-1;
}
void enqueueCircle(CircularQueue_t* queue, int item)
{
    if (isFullCircle(*queue))
    {
        printf("It is full");
        exit(-3);
    }
    if (isEmptyCircle(*queue))
    {
        queue->front=0;
    }
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->elements[queue->rear]=item;
}
int dequeueCircle(CircularQueue_t* queue)
{
    if (isEmptyCircle(*queue))
    {
        printf("is empty");
        return INT_MIN;
    }
    int save=queue->elements[queue->front];
    if (queue->front==queue->rear)
    {
        queue->front=queue->rear=-1;
    }
    else
    {
        queue->front=(queue->front+1)%queue->capacity;
    }
    return  save;
}
void displayCircle(CircularQueue_t queue) {
    if (isEmptyCircle(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (i != queue.rear) {
        printf("%d ", queue.elements[i]);
        i = (i + 1) % queue.capacity;
    }
    printf("%d\n", queue.elements[queue.rear]);
}

int peekCircle(CircularQueue_t queue) {
    if (isEmptyCircle(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue.elements[queue.front];
}