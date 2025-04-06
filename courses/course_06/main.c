#include <stdio.h>

#include "circle_queue_h/circle_queue.h"
#include "simple_queue_h/simple_queue.h"

int main() {
    Simple_Queue_t queue;

    // Queue létrehozása kapacitással 5
    createQueue(5, &queue);

    // Hozzáadás elemeket a sorhoz
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Fájl beolvasása a sorba
    loadQueueFromFile(&queue, "queue_data.txt");

    // Sor kiírása
    display(queue);

    // Elem lekérése a sor elejéről (peek)
    int frontItem = peek(queue);
    if (frontItem != -1) {
        printf("Front item is: %d\n", frontItem);
    }

    // Kiveszünk egy elemet a sorból
    int dequeuedItem = dequeue(&queue);
    printf("Dequeued item: %d\n", dequeuedItem);

    // Sor kiírása a művelet után
    display(queue);

    // További elemek hozzáadása és kiveszése
    enqueue(&queue, 60);
    display(queue);
    dequeuedItem = dequeue(&queue);
    printf("Dequeued item: %d\n", dequeuedItem);

    // Sor törlése
    destroyQueue(&queue);

    CircularQueue_t circle_queue;
    int capacity = 5;

    // Körkörös sor létrehozása
    createCircleQueue(capacity, &circle_queue);
    printf("Queue created with capacity %d.\n", capacity);

    // Elek hozzáadása
    enqueueCircle(&circle_queue, 10);
    enqueueCircle(&circle_queue, 20);
    enqueueCircle(&circle_queue, 30);
    enqueueCircle(&circle_queue, 40);
    enqueueCircle(&circle_queue, 50);

    // Fájl beolvasása a körkörös sorba
    loadCircleQueueFromFile(&circle_queue, "circle_queue_data.txt");

    // Sor állapotának megjelenítése
    printf("Queue after enqueuing 5 items: ");
    displayCircle(circle_queue);

    // Próbálkozás egy további elem hozzáadásával (a sor már tele van)
    enqueueCircle(&circle_queue, 60);

    // Elem eltávolítása
    printf("Dequeued item: %d\n", dequeueCircle(&circle_queue));

    // Sor állapotának megjelenítése
    printf("Queue after dequeuing an item: ");
    displayCircle(circle_queue);

    // Új elem hozzáadása
    enqueueCircle(&circle_queue, 60);
    printf("Queue after enqueuing an item: ");
    displayCircle(circle_queue);

    // Az első elem lekérése
    printf("Front item: %d\n", peekCircle(circle_queue));

    // A sor törlése és memóriakezelés
    destroyCircleQueue(&circle_queue);
    printf("Queue destroyed.\n");
    return 0;
}
