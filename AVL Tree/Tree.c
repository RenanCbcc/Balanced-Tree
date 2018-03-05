//
// Created by Renan on 05/03/2018.
//
#include "Tree.h"
struct Data {
    int id;
    char *name;
};

struct Node {
    int height;
    struct Data information;
    struct Node *left;
    struct Node *right;
};

// ----------------------------------------------------------------------
Node* createTree(){
    struct Node * root = (struct Node*) malloc(sizeof(Node));
    if(root !=NULL){
        *root = NULL; // There is not any Node allocated after this.
    }
    else{ return root;}
}
// ----------------------------------------------------------------------
void freeTree(Node* root) {
    if(root == NULL){
        return;
    } else{
        freeNode(root);
        free(root);
    }
}
// ----------------------------------------------------------------------
void freeNode(Node* root){
    if (root == NULL) {
        return;
    }else{
        freeNode(&(*root)->left);
        freeNode(&(*root)->right);
        free(root);
        root= NULL;
    }
}

// ----------------------------------------------------------------------

int treeHeight(Node* root) {
    if (isEmpty(root)) {
        printf("Node currently empty");
        return 0;
    }
    int leftHeight = treeHeight(&(*root)->left);
    int rightHeight = treeHeight(&(*root)->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }

}
// ----------------------------------------------------------------------
int nodeHeight(Node* node){
    if(node == NULL){
        return -1;
    } else{
        return (*node)->height;
    }
}
// ----------------------------------------------------------------------
int isBigger(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

// ----------------------------------------------------------------------
int balaceFactor(Node* node) {
    return labs(nodeHeight(&(*node)->left) - nodeHeight(&(*node)->right));
}

// ----------------------------------------------------------------------
int isEmpty(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (*root == NULL) {
        return 0;
    }

    return 1;
}
// ----------------------------------------------------------------------
int nodesNumber(Node* root) {
    if (isEmpty(root)) {
        printf("Node currently empty");
        return 0;
    }
    int left_total = nodesNumber(&((*root)->left));
    int right_total = nodesNumber(&((*root)->right));
    return (left_total + right_total +1);
}
// ----------------------------------------------------------------------
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    if(*root !=NULL){
        printf("%d\n", (*root)->information); //TODO
        preOrder(&(*root)->left);
        preOrder(&(*root)->right);
    }
}
// ----------------------------------------------------------------------
void posOrder(Node* root){
    if(root == NULL){
        return;
    }
    if(*root !=NULL){
        posOrder(&(*root)->left);
        posOrder(&(*root)->right);
        printf("%d\n", (*root)->information); //TODO
    }

}
// ----------------------------------------------------------------------
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    if(*root !=NULL){
        inOrder(&(*root)->left);
        printf("%d\n", (*root)->information); //TODO
        inOrder(&(*root)->right);
    }

}
// ----------------------------------------------------------------------
int findNode(Node* root,Person person){
    if(isEmpty(root)){
        return -1;
    } else{
        Node *current = root;
        while (current!=NULL){
            if(isEquals(person,&(*current)->information)){
                return 1; //TODO print information
            }
            if( person->id > (*current)->information.id){
                *current = (*current)->right;
            }else{
                *current = (*current)->left;
            }
        }
        return 0;
    }
}
// ----------------------------------------------------------------------
int isEquals(Person this, Person other){
    if(this->id == other->id && this->name == other->name){
        return 1;
    }else{
        return 0;
    }
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
