//
// Created by Dora on 2025. 04. 10..
//

#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H
#define MAX_CAPACITY 20
#define MAX_NAME_LENGTH 20

// Enum típus a színekhez
typedef enum {
    RED,WHITE,YELLOW,BLACK,OTHER
} Szin;

// Strukturáljuk a labda típusát
typedef struct {
    int atmero;
    Szin szin;
    int alairva;  // 1: aláírt, 0: nem aláírt
} Labda;

// Sor típus, azaz polc
typedef struct {
    Labda* elements;
    int front; // Sor első eleme
    int rear; // Sor utolsó eleme
    int capacity;
    int db_szines;
} Polc;

//simple queue fgv
void createQueue(int capacity, Polc *queue);
void destroyQueue(Polc* queue);
bool isFull(Polc queue);
bool isEmpty(Polc queue);
void enqueue(Polc* queue, Labda item);
Labda dequeue(Polc* queue);
void display(Polc queue);
Labda peek(Polc queue);

// Függvények deklarálása
void readfromfile(Polc *polcfeher, Polc *polcfekete);
void beolvas_labda(Labda *labda);
void kiir_labda(Labda labda);
Szin szin_bekero(const char* szin_str);
void transfer_labdak(Polc *polc1, Polc *polc2, Polc *polcszines);
#endif //SIMPLEQUEUE_H
