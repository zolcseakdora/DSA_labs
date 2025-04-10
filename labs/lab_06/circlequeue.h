//
// Created by Dora on 2025. 03. 27..
//

#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H
typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}CircularQueue_t;

void createQueue(int capacity, CircularQueue_t *queue);
/**
 * Deallocates the elements array -> free
 * @param queue
 */
void destroyQueue(CircularQueue_t* queue);
/**
 * Checks whether the queue is full or not
 * @param queue
 * @return true/false
 */
bool isFull(CircularQueue_t queue);
/**
 * Checks whether the queue is empty or not
 * @param queue
 * @return true/false
 */
bool isEmpty(CircularQueue_t queue);
/**
 * Adds a new item to the end of the queue
 * @param queue
 * @param item
 */
void enqueue(CircularQueue_t* queue, int item);
/**
 * Removes the first item from the queue
 * @param queue
 * @return
 */
int dequeue(CircularQueue_t* queue);
/**
 * Prints all items of the queue
 * @param queue
 */
void display(CircularQueue_t queue);
/**
 * Returns the element in the front
 * @param queue
 * @return the element in the front
 */
int peek(CircularQueue_t queue);
#endif //CIRCLEQUEUE_H
