//
// Created by Dora on 2025. 05. 08..
//

#ifndef LISTA_H
#define LISTA_H
typedef struct Datum {
    int ev;
    int honap;
    int nap;
} Datum;

typedef struct Barat {
    char nev[100];
    Datum szuletesiDatum;
    char nem;
    int bulizas;
    int eletkor;
} Barat;

typedef struct Node {
    Barat data;
    struct Node* next;
} Node;
Node* newNode(Barat uj);
bool isEmpty(Node *head);
void insertAtEnd(Node** head, Barat uj);
void printList(Node* head);
int eletkor(Datum szuletesiDatum);
int elegBaratBulira(Node* head, char neveket[][100]);
#endif //LISTA_H
