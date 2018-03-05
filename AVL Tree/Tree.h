//
// Created by Renan on 05/03/2018.
//

#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node * Node;
typedef struct Data *Person;

// ----------------------------------------------------------------------
Node * createTree();
int insertNode(Node* root,Person person);
int removeNode(Node* root,Person person);
int isEmpty(Node* root);
int treeHeight(Node* root);
int nodeHeight(Node* node);
int nodesNumber(Node* root);
int findNode(Node* root,Person person);
int isBigger(int x, int y);
int balaceFactor(Node* node);
// ----------------------------------------------------------------------
void freeTree(Node* root);
void freeNode(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
void inOrder(Node* root);
int isEquals(Person this, Person other);

#endif //AVL_TREE_TREE_H
