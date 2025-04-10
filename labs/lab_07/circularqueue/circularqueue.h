//
// Created by Dora on 2025. 04. 10..
//

#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#define MAX_CAPACITY 20
#define MAX_NAME_LENGTH 20

// Enum típus a színekhez
typedef enum {
    RED,WHITE,BLACK,YELLOW,OTHER
} Szin;

// Strukturáljuk a labda típusát
typedef struct {
    int atmero;
    Szin szin;
    int alairva;  // 1: aláírt, 0: nem aláírt
} Labda;

// Körkörös sor (polc) típus
typedef struct {
    Labda *elements;
    int front; // Sor első eleme
    int rear;// Sor utolsó eleme
    int capacity;
    int db_szines;
} Polc;
//circular queue
void createQueue_circle(int capacity,Polc *queue);
void destroyQueue_circle(Polc * queue);
bool isFull_circle(Polc queue);
bool isEmpty_circle(Polc queue);
void enqueue_circle(Polc * queue, Labda item);
Labda dequeue_circle(Polc * queue);
void display_circle(Polc queue);
void readfromfile(Polc *polcfeher, Polc *polcfekete);
Labda peek(Polc queue) ;

// Függvények deklarálása
void beolvas_labda(Labda *labda);
void kiir_labda(Labda labda);
Szin szin_bekero(const char* szin_str);
void transfer_labdak(Polc *polc1, Polc *polc2,Polc *polcszines);
#endif //CIRCULARQUEUE_H
