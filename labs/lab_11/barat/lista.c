//
// Created by Dora on 2025. 05. 08..
//

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* newNode(Barat uj) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) {
        exit(-1);
    }
    new_node->data = uj;
    new_node->next = NULL;
    return new_node;
}
bool isEmpty(Node *head) {
    return head == NULL;
}
void insertAtEnd(Node** head_ref,Barat uj) {
    Node* new_node = newNode(uj);
    Node* last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}
void printList(Node* node)
{
    while (node != NULL) {
        printf("Nev: %-15s Szuletett: %4d-%02d-%02d Nem: %c  Bulizas: %d Eletkor: %d\n", node->data.nev,
            node->data.szuletesiDatum.ev,
            node->data.szuletesiDatum.honap,
            node->data.szuletesiDatum.nap,
            node->data.nem,
            node->data.bulizas,
            node->data.eletkor);
        node = node->next;
    }
}
int eletkor(Datum szuletesiDatum)
{
    int ev = 2025;
    int honap = 5;
    int nap = 8;
    int kor = ev - szuletesiDatum.ev;
    if (szuletesiDatum.honap > honap ||
        (szuletesiDatum.honap == honap && szuletesiDatum.nap > nap)) {
        kor--;
        }
    return kor;
}
int elegBaratBulira(Node* head, char neveket[][100])
{
    int count = 0;
    while (head != NULL) {
        if (eletkor(head->data.szuletesiDatum) >= 20 && head->data.bulizas >= 5) {
            strcpy(neveket[count], head->data.nev);
            count++;
        }
        head = head->next;
    }
    return count;
}