//
// Created by Dora on 2025. 05. 15..
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "book.h"

typedef struct Node{
    Book info;
    struct Node *left, *right;
}Node;
Node *createNewNode(Book newData);
void destroyBinaryTree(Node **root);
Node *insert(Node *node, Book key);
void inorderTraversal(Node *root);
Node* search(Node* root, char *key);
#endif //BINARY_SEARCH_TREE_H
