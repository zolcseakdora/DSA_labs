//
// Created by Dora on 2025. 04. 10..
//

#include "circularqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Labda adatainak beolvasása
void beolvas_labda(Labda *labda) {
    char szin_str[MAX_NAME_LENGTH];

    printf("Labda átmérője: ");
    scanf("%d", &labda->atmero);

    getchar(); // Az Enter karakter eltávolítása a bufferből

    printf("Labda színe (PIROS, FEHER, FEKETE, SARGA, MAS): ");
    fgets(szin_str, sizeof(szin_str), stdin);
    szin_str[strcspn(szin_str, "\n")] = '\0';  // Az utolsó új sort eltávolítjuk

    labda->szin = szin_bekero(szin_str);

    printf("Van-e aláírva (igen/nem): ");
    scanf("%d",&labda->alairva);
}

// Labda adatainak kiírása
void kiir_labda(Labda labda) {
    char *szin_str;
    switch (labda.szin) {
        case RED: szin_str = "piros"; break;
        case WHITE: szin_str = "fehér"; break;
        case BLACK: szin_str = "fekete"; break;
        case YELLOW: szin_str = "sárga"; break;
        case OTHER: szin_str = "más"; break;
        default: szin_str = "ismeretlen"; break;
    }

    printf("Átmérő: %d, Szín: %s, Aláírt: %d\n", labda.atmero, szin_str, labda.alairva);
}

// Segédfüggvény a szín konvertálásához
Szin szin_bekero(const char* szin_str)
{
    if (strcmp(szin_str, "PIROS") == 0) return RED;
    if (strcmp(szin_str, "FEHER") == 0) return WHITE;
    if (strcmp(szin_str, "FEKETE") == 0) return BLACK;
    if (strcmp(szin_str, "SARGA") == 0) return YELLOW;
    return OTHER;
}

void readfromfile(Polc *polcfeher, Polc *polcfekete)
{
    FILE* file=fopen("../input.txt","r");
    if (!file)
    {
        printf("hiba");
        return;
    }
    int atmero;
    char szin[20];
    int alairva;
    for (int i=0; i<MAX_CAPACITY; i++)
    {
        if (fscanf(file,"%d",&atmero)!=1)
        {
            printf("nem tudja beolvasni");
            break;
        }
        fgetc(file);
        if (fscanf(file,"%s",szin)!=1)
        {
            printf("nem tudja beolvasni");
            break;
        }
        if (fscanf(file,"%d",&alairva)!=1)
        {
            printf("nem tudja beolvasni");
            break;
        }
        Labda labda={
            atmero,
            szin_bekero(szin),
            alairva
        };
        if (labda.szin==WHITE)
        {
            enqueue_circle(polcfeher,labda);
        }
        if (labda.szin==BLACK)
        {

            enqueue_circle(polcfekete,labda);
        }
        int randomszam=rand()%2;
        if (randomszam==0)
        {
            dequeue_circle(polcfeher);
            enqueue_circle(polcfeher,labda);
            polcfeher->db_szines++;
        }
        if (randomszam==1)
        {
        dequeue_circle(polcfekete);
            enqueue_circle(polcfekete,labda);
            polcfeher->db_szines++;
        }

    }
    fclose(file);

}
void createQueue_circle(int capacity, Polc *queue) {
    queue->capacity = capacity;
    queue->elements = (Labda*)malloc(capacity*sizeof(Labda));
    if (!queue->elements) {perror("Memory allocation error!"); exit(-1);}
    queue->front = queue->rear = -1;
    queue->db_szines=0;
}
void destroyQueue_circle(Polc *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->capacity = 0;
    queue->front = queue->rear = -1;
}
bool isFull_circle(Polc queue){
    return (queue.front == (queue.rear + 1) % queue.capacity);
}
bool isEmpty_circle(Polc queue) {
    return (queue.front == -1);
}
void enqueue_circle(Polc *queue, Labda item) {
    if (isFull_circle(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty_circle(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
}
Labda dequeue_circle(Polc *queue) {
    Labda ures={0,OTHER,0};
    if (isEmpty_circle(*queue)) {
        printf("Queue is empty!\n");
        return ures;
    }
    Labda temp = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    if (temp.szin!=WHITE && temp.szin!=BLACK)
    {
        queue->db_szines--;
    }
    return temp;
}
void display_circle(Polc queue) {
    if (isEmpty_circle(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (true) {
        printf("%d ", queue.elements[i]);
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    printf("\n");
}
Labda peek(Polc queue) {
    Labda ures={0,OTHER,0};
    if (isEmpty_circle(queue)) {
        printf("Queue is empty!\n");
        return ures;
    }
    return queue.elements[queue.front];
}

// Labdák áthelyezése egyik polcról a másikra
void transfer_labdak(Polc *polc1, Polc *polc2,Polc * polcszines) {
    while (!isEmpty_circle(*polc1)) {
        Labda labda = dequeue_circle(polc1);
        enqueue_circle(polcszines, labda);
    }
    while (!isEmpty_circle(*polc2)) {
        Labda labda = dequeue_circle(polc2);
        enqueue_circle(polcszines, labda);
    }
}
