//
// Created by Dora on 2025. 04. 10..
//

#ifndef STACK_H
#define STACK_H

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

// Ládák struktúrája
typedef struct {
    Labda *elements;
    int top;  // Legfelső elem indexe
    int capacity;
    int db_alairt;
} Lada;
//stack fgv
void createStack(int capacity, Lada* stack);
void destroyStack(Lada* stack);
bool isFull(Lada stack);
bool isEmpty(Lada stack);
void push(Lada* stack, Labda item);
Labda pop(Lada* stack);
Labda peek(Lada stack);
int size(Lada stack);

// Függvények deklarálása
void beolvas_labda(Labda *labda);
void kiir_labda(Labda labda);
Szin szin_bekero(const char* szin_str);
void legnagyobb_atmero_labda(Lada *ladapiros, Lada *ladafeher, Lada *ladaszines);
void kiveve_alairt(Lada *lada, Lada *lada2, Lada *lada3);

#endif //STACK_H
