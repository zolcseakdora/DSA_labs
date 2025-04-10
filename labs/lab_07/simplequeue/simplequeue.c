//
// Created by Dora on 2025. 04. 10..
//

#include "simplequeue.h"
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
Szin szin_bekero(const char* szin_str) {
    if (strcmp(szin_str, "RED") == 0) return RED;
    if (strcmp(szin_str, "WHITE") == 0) return WHITE;
    if (strcmp(szin_str, "BLACK") == 0) return BLACK;
    if (strcmp(szin_str, "YELLOW") == 0) return YELLOW;
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
            enqueue(polcfeher,labda);
        }
        if (labda.szin==BLACK)
        {

            enqueue(polcfekete,labda);
        }
        int randomszam=rand()%2;
        if (randomszam==0)
        {
            dequeue(polcfeher);
            enqueue(polcfeher,labda);
            polcfeher->db_szines++;
        }
        if (randomszam==1)
        {
            dequeue(polcfekete);
            enqueue(polcfekete,labda);
            polcfeher->db_szines++;
        }

    }
    fclose(file);

}
void createQueue(int capacity, Polc* queue){
    queue->capacity=capacity;
    queue->rear=queue->front=-1;
    queue->elements=(Labda*)malloc(capacity*sizeof(Labda));
    queue->db_szines=0;
    if (!queue->elements){
        printf("Memory allocation error");
        exit(-1);
    }
}

void destroyQueue(Polc* queue){
    free(queue->elements);
    queue->elements = NULL;
    queue->front = queue->rear = -1;
    queue->capacity = 0;
}

bool isFull(Polc queue){
    return queue.rear == queue.capacity - 1;
}

bool isEmpty(Polc queue) {
    return queue.front == -1;
}

void enqueue(Polc* queue, Labda item) {
    if (isFull(*queue)) {
        printf("The queue is full\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->elements[queue->rear++] = item;
}

Labda dequeue(Polc* queue) {
    if (isEmpty(*queue))
    {
        printf("The queue is empty");
        exit(-3);
    }
    Labda save=queue->elements[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear=-1;
    }
    else {
        queue->front++;
    }
    if (save.szin!=WHITE && save.szin!=BLACK)
    {
        queue->db_szines--;
    }
    return save;
}

void display(Polc queue){
    if (isEmpty(queue)) {
        printf("The queue is empty");
        exit(-3);
    }
    for (int i=queue.front; i<=queue.rear; i++) {
        printf("%s ", queue.elements[i]);
    }
    printf("\n");
}

Labda peek(Polc queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
        exit(-3);
    }
    return queue.elements[queue.front];
}
// Labdák áthelyezése egyik polcról a másikra
void transfer_labdak(Polc *polc1, Polc *polc2, Polc *polcszines) {
    while (!isEmpty(*polc1))
    {
        Labda labda=dequeue(polc1);
        if (labda.szin!=WHITE && labda.szin!=BLACK)
        {
            enqueue(polcszines,labda);
        }
    }
    while (!isEmpty(*polc2))
    {
        Labda labda=dequeue(polc2);
        if (labda.szin!=WHITE && labda.szin!=BLACK)
        {
            enqueue(polcszines,labda);
        }
    }

}