//
// Created by Dora on 2025. 05. 15..
//

#ifndef LIST_H
#define LIST_H
#include "book.h"

typedef struct Node{
    Book data;
    struct Node* next;
}Node;
Node* newNode(Book new_data);
void freeList(Node **head);
void insertAtEnd(Node** head_ref, Book new_data);
bool isEmpty(Node *head);
#endif //LIST_H
