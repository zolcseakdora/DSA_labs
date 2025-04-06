//
// Created by Dora on 2025. 04. 06..
//

#ifndef CIRCLE_QUEUE_H
#define CIRCLE_QUEUE_H
typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}CircularQueue_t;
void loadCircleQueueFromFile(CircularQueue_t *queue, const char *filename);
/**
* Creates the queue data structure, allocates memory for elements
* @param capacity
* @param queue
*/
void createCircleQueue(int capacity, CircularQueue_t *queue);
/**
* Deallocates the elements array -> free
* @param queue
*/
void destroyCircleQueue(CircularQueue_t* queue);
/**
* Checks whether the queue is full or not
* @param queue
* @return true/false
*/
bool isFullCircle(CircularQueue_t queue);
/**
* Checks whether the queue is empty or not
* @param queue
* @return true/false
*/
bool isEmptyCircle(CircularQueue_t queue);
/**
* Adds a new item to the end of the queue
* @param queue
* @param item
*/
void enqueueCircle(CircularQueue_t* queue, int item);
/**
* Removes the first item from the queue
* @param queue
* @return
*/
int dequeueCircle(CircularQueue_t* queue);
/**
* Prints all items of the queue
* @param queue
*/
void displayCircle(CircularQueue_t queue);
/**
* Returns the element in the front
* @param queue
* @return the element in the front
*/
int peekCircle(CircularQueue_t queue);
#endif //CIRCLE_QUEUE_H
