//
// Created by Dora on 2025. 05. 15..
//

#include "../headers/binary_search_tree.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../headers/contans.h"
Node *createNewNode(Book newData) {
    Node *newItem = (Node *) malloc(sizeof(Node));
    if (!newItem) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL;
    return newItem;
}
void destroyBinaryTree(Node **root) {
    if ((*root) != NULL) {
        destroyBinaryTree(&(*root)->left);
        destroyBinaryTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}
Node *insert(Node *node, Book key) {
    if(node == NULL)
    {
        return createNewNode(key);
    }
    if(strcmp(node->info.title,key.title)<0)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        node->left = insert(node->left, key);
    }
    return node;
}
void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printBook(root->info);
    inorderTraversal(root->right);
}
Node* search(Node* root, char *key)
{
    if (root == NULL ) {
        return NULL;
    }
    if (strcmp(key,root->info.title)<0) {
        return search(root->left, key);
    }
    else if (strcmp(key,root->info.title)>0){
            return search(root->right, key);
    }
    else return root;

}