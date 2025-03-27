#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplequeue.h"

int main(void)
{
    Simple_Queue_t simple_queue;
    createQueue(100,&simple_queue);
    int choice;
    do {
        printf("Choose from the following options:"
        "\n\t- Check if queue is empty: 1"
        "\n\t- Check if queue is full: 2"
        "\n\t- Add a new car to the queue: 3"
        "\n\t- Remove a car from the queue: 4"
        "\n\t- Display the cars waiting in the queue: 5"
        "\n\t- Exit: 6"
        "\n\nChoose an option:");
        scanf("%i", &choice);
        switch (choice)
        {
        case 1: if (isEmpty(simple_queue))
        {
            printf("is empty\n");
        }
        else
        {
            printf("is not empty\n");
        }
            break;
        case 2: if (isFull(simple_queue))
        {
            printf("is full\n");
        }else
        {
            printf("is not full\n");
        }
            break;
        case 3:
            {
                char car[10];
                //fgets(car,sizeof(car),stdin);
                scanf("%s",car);
                enqueue(&simple_queue,car);
                break;
            }
        case 4:dequeue(&simple_queue);
            break;
        case 5:display(simple_queue);
            break;
        case 6:printf("exit...\n");
            break;
            default: printf("Invalid choice, try again.\n");
        }
    }while (choice!=6);
    destroyQueue(&simple_queue);
    return 0;
}
