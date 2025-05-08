//
// Created by Dora on 2025. 04. 17..
//

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int new_data) {
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
void insertAtBeginning(Node** head_ref, int new_data) {
    // Allocate memory to a node
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    // Move head to new node
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
        }
    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}
void deleteFromBeginning(Node **head_ref) {
    if(isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}
void deleteFromEnd(Node **head_ref) {
    if(isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }
    Node* last = *head_ref, *prev;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}
void deleteNode(Node** head_ref,int key)
{
    Node *temp=*head_ref,*prev;
    if (temp!=NULL && temp->data==key)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data != key)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) return;
    prev->next =temp->next;
    free(temp);
}
bool searchNode(Node* head_ref, int key) {
    Node* current = head_ref;
    while (current != NULL) {
        if (current->data == key) return true;
        current = current->next;
    }
    return false;
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%4d ", node->data);
        node = node->next;
    }
}
void sortLinkedList(Node* head_ref) {
    Node *p = (head_ref);
    Node *q;
    while (p->next != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                int aux = p->data;
                p->data = q->data;
                q->data = aux;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void orderedList(Node **head_ref, int new_data) {
    Node *prev=NULL, *last=NULL;
    Node *node = newNode(new_data);
    if (isEmpty(*head_ref)) {
        (*head_ref) = node;
        return;
    } else {
        if ((*head_ref)->data >= new_data) {
        insertAtBeginning(head_ref, new_data);
        return;
        }
    }
    last = (*head_ref);
    prev = NULL;
    while (last != NULL && last->data <= new_data) {
        prev = last;
        last = last->next;
    }
    node->next = last;
    if (prev != NULL) {
        prev->next = node;
    }
}
int getDigitList(int number, Node **head) {
    // Szám számjegyeinek beillesztése hátulról
    while (number > 0) {
        int digit = number % 10;
        insertAtEnd(head, digit);
        number /= 10;
    }
    return 0;
}

void addDigitLists(Node* head1, Node* head2, Node **result) {
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry) {
        int sum = carry;
        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }
        insertAtEnd(result, sum % 10);
        carry = sum / 10;
    }
}

int listToInteger(Node* head) {
    int result = 0;
    int multiplier = 1;
    while (head != NULL) {
        result += head->data * multiplier;
        multiplier *= 10;
        head = head->next;
    }
    return result;
}

void insertZeroAfterEven(Node **head) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            Node* new_zero = newNode(0);
            new_zero->next = current->next;
            current->next = new_zero;
            current = new_zero->next;
        } else {
            current = current->next;
        }
    }
}
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

