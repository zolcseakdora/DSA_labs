//
// Created by Dora on 2025. 03. 27..
//

#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H
typedef struct
{

}CircularQueue_t;
void createQueue_circle(int capacity, CircularQueue_t *queue);

void destroyQueue_circle(CircularQueue_t * queue);

bool isFull_circle(CircularQueue_t queue);

bool isEmpty_circle(CircularQueue_t queue);

void enqueue_circle(CircularQueue_t * queue, int item);

int dequeue_circle(CircularQueue_t * queue);

void display_circle(CircularQueue_t queue);

#endif //CIRCLEQUEUE_H
