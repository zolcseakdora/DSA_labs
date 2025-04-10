//
// Created by Dora on 2025. 04. 10..
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAPACITY 20
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
    if (strcmp(szin_str, "PIROS") == 0) return RED;
    if (strcmp(szin_str, "FEHER") == 0) return WHITE;
    if (strcmp(szin_str, "FEKETE") == 0) return BLACK;
    if (strcmp(szin_str, "SARGA") == 0) return YELLOW;
    return OTHER;
}

// Legnagyobb átmérőjű labda a ládában
void legnagyobb_atmero_labda(Lada *lada, Lada *lada2, Lada *lada3) {
    int max=peek(*lada).atmero;
    int max2=peek(*lada2).atmero;
    int max3=peek(*lada3).atmero;
    if (max>max2 && max>max3)
    {
        printf("A max a pirosban van");
        return;
    }

}

// Kivétel addig, amíg minden láda tetején aláírt labda nem lesz
void kiveve_alairt(Lada *lada, Lada *lada2, Lada *lada3) {
    while (!isEmpty(*lada)) {
        Labda labda = peek(*lada);
        if (labda.alairva) {
            break;
        }
        pop(lada);
    }
    while (!isEmpty(*lada2)) {
        Labda labda = peek(*lada2);
        if (labda.alairva) {
            break;
        }
        pop(lada2);
    }
    while (!isEmpty(*lada3)) {
        Labda labda = pop(lada3);
        if (labda.alairva) {
            break;
        }
        pop(lada2);
    }
}
void readfromfile(Lada *lada,Lada *lada2,Lada *lada3)
{
    FILE *file=fopen("../input.txt","r");
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
        if(fscanf(file,"%d",&atmero)!=1)
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
        if (labda.szin==RED)
        {
            push(lada,labda);
            lada->db_alairt+=alairva;
            continue;;
        }
        if (labda.szin==WHITE)
        {
            push(lada2,labda);
            lada2->db_alairt+=alairva;
            continue;
        }
        push(lada3,labda);
        lada3->db_alairt+=alairva;
    }
    fclose(file);
}
void createStack(int capacity, Lada* stack){
  stack->capacity = capacity;
  stack->top = -1;
  stack->elements = (Labda *)malloc(stack->capacity* sizeof(Labda));
    stack->db_alairt=0;
  if(!(stack->elements)){
    printf("error");
    exit(-1);
   }
}
//FELSZABADITAS
void destroyStack(Lada* stack){
  stack->capacity=0;
  stack->top=-1;
  free(stack->elements);
  stack = NULL;
}
//ELLENORZI HOGY TELE VAN-E
bool isFull(Lada stack){
    if(stack.top==stack.capacity-1){
      return true;
    }
    return false;
}
//ELLENORZI HOGY URES-E
bool isEmpty(Lada stack){
   if (stack.top==-1)
    {
        return true;
    }
    return false;
}
//BETESZ EGY ERTEKET HATULRA VAGYIS NOVELI A "TOP" ERTEKET ES ODA SZURJA BE
void push(Lada* stack, Labda item){
  if(isFull(*stack)){
    printf("A verem tele van");
  }
  stack->elements[++stack->top]=item;
}
//KIVESZ EGY ELEMET AZ UTOLSO POZICIOROL ES UTANA CSOKKENTEM A "TOP" ERTEKET
Labda pop(Lada* stack){
    Labda ures={0,OTHER,0};
  if(isEmpty(*stack)){
    printf("A verem ures");
    return ures;
  }
    if (stack->elements[stack->top].alairva)
    {
        stack->db_alairt--;
    }
  return stack->elements[stack->top--];
}
//MEGMONDJA HOGY A LEGFELSO HELYEN AMI A "TOP" MILYEN ELEM VAN
Labda peek(Lada stack){
    Labda ures={0,OTHER,0};
  if(isEmpty(stack)){
    printf("A verem ures");
    return ures;
  }
  return stack.elements[stack.top];
}
//MEGMONDJA HOGY HANY ELEM VAN A STACKBEN
int size(Lada stack) {
    return stack.top + 1;
}




