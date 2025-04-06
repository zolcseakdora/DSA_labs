#include "../simple_queue_h/simple_queue.h"

#include <stdio.h>
#include <stdlib.h>

void loadQueueFromFile(Simple_Queue_t *queue, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int item;
    while (fscanf(file, "%d", &item) != EOF) {
        enqueue(queue, item);
    }

    fclose(file);
}

void createQueue(int capacity, Simple_Queue_t* queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (int*)malloc(capacity * sizeof(int));
    if (!queue->elements) {
        exit(-1);
    }
}

void destroyQueue(Simple_Queue_t* queue) {
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
}

bool isEmpty(Simple_Queue_t queue) {
    return queue.front == -1;
}

bool isFull(Simple_Queue_t queue) {
    return queue.rear == queue.capacity - 1;
}

void enqueue(Simple_Queue_t* queue, int item) {
    if (isFull(*queue)) {
        printf("Queue is full, cannot enqueue item.\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->elements[++queue->rear] = item;
}

int dequeue(Simple_Queue_t* queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty, cannot dequeue item.\n");
        return -1;  // Return -1 to indicate that the queue is empty
    }
    int item = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;  // Reset the queue when it's empty
    } else {
        queue->front++;
    }
    return item;
}

int peek(Simple_Queue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, no front item.\n");
        return -1;  // Return -1 if the queue is empty
    }
    return queue.elements[queue.front];
}

void display(Simple_Queue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.elements[i]);
    }
    printf("\n");
}
