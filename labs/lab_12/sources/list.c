//
// Created by Dora on 2025. 05. 15..
//

#include "../headers/list.h"

#include <stddef.h>
#include <stdlib.h>

void freeList(Node **head)
{
    while (*head != NULL)
    {
        Node *temp = *head;
        *head =(*head)->next;
        free(temp);
    }
    *head = NULL;
}
void insertAtEnd(Node** head_ref, Book new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}
Node *newNode(Book new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) {
        exit(-1);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
bool isEmpty(Node *head) {
    return head == NULL;
}