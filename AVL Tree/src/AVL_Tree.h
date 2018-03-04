/*
 * AVL_Tree.h
 *
 *  Created on: 4 de mar de 2018
 *      Author: Renan
 */

#ifndef AVL_TREE_H_
#define AVL_TREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Node;
typedef struct Data * Person;

// ----------------------------------------------------------------------
Node * creat_Tree();
int insert(Node* root,Person person);
int remove(Node* root,Person person);
int isEmpty(Node* root);
int treeHeight(Node* root);
int nodeHeight(Node* node);
int nodesNumber(Node* root);
int find(Node* root,Person person);
int isBigger(int x, int y);
int balaceFactor(Node* node);
// ----------------------------------------------------------------------
void free_tree(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
void inOrder(Node* root);
#endif /* AVL_TREE_H_ */
