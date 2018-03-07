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
    struct Data *information;
    struct Node *left;
    struct Node *right;
};

// ----------------------------------------------------------------------
Node* createTree(){
    Node * root = ( Node*) malloc(sizeof(Node));
    if(root != NULL){
        *root = NULL; // There is not any Node allocated after this.
    }else{
        return root;
    }
}

// ----------------------------------------------------------------------
int insertNode(Node* root,Person *person){
    int response;
    if(isEmpty(root)){
        Node *new;
        new = (Node*) malloc(sizeof(Node));
        if(new == NULL){
            return 0;
        }else{
            (*new)->information = *person;
            (*new)->right = NULL;
            (*new)->left = NULL;
            root = new;
            return 1;
        }
    } else{
        Node *current = root;
        if((*person)->id < (*current)->information->id){
            if(( response = (insertNode(&(*current)->left, person)) == 1)){
                if(balaceFactor(current)>= 2){
                    if((*person)->id < (*root)->information->id){
                        simpleLeftRotation(root);
                    }else{
                        simpleRightRotation(root);
                    }
                }
            }
        } else{
            if((*person)->id> (*current)->information->id){
                if(( response = insertNode(&(*current)->right,person))==1){
                    if(balaceFactor(current)>=2){
                        if((*root)->right->information->id < (*person)->id){
                            simpleRightRotation(root);
                        }else{
                            simpleLeftRotation(root);
                        }
                    }
                }
            }else{
                return 0; // Value duplicated.
            }
        }
        (*current)->height = bigger(nodeHeight(&(*current)->left),nodeHeight(&(*current)->right)) + 1;

    }
    return response;
}

// ----------------------------------------------------------------------
int removeNode(Node* root,Person *person){
    if(*root == NULL){
        return 0;
    }
    int response;
    if((*person)->id < (*root)->information->id){
        if(( response = (removeNode(&(*root)->left, person)) == 1)){
            if(balaceFactor(root) >=2){
                if(nodeHeight(&(*root)->left->right) <= nodeHeight(&(*root)->right->right)){
                    simpleRightRotation(root);
                }else{
                    doubleRightRotation(root);
                }
            }
        }
    }
    if((*person)->id > (*root)->information->id){
        if(( response = (removeNode(&(*root)->right, person)) == 1)){
            if(balaceFactor(root) >=2){
                if(nodeHeight(&(*root)->left->right) <= nodeHeight(&(*root)->left->left)){
                    simpleLeftRotation(root);
                }else{
                    dualRotationLeft(root);
                }
            }
        }
    }

    if((*root)->information->id == (*person)->id){
        if( (*root)->left == NULL || (*root)->right == NULL ){
            //Node has only one child
            Node *old = root;
            if( (*root)->left != NULL){
                root = &(*root)->left;
            }else{
                root = &(*root)->right;
            }
           free(old);
        }else{
            Node* temporary = minimum(&(*root)->right);
            (*root)->information->id = (*temporary)->information->id;
            removeNode(&(*root)->right,&(*root)->information);;
            if(balaceFactor(root) >=2){
                if(nodeHeight(&(*root)->left->right) <= nodeHeight(&(*root)->left->left)){
                    simpleLeftRotation(root);
                }else{
                    dualRotationLeft(root);
                }
            }
        }
        if((*root) != NULL){
            (*root)->height = bigger(nodeHeight(&(*root)->left),nodeHeight(&(*root)->right)) +1;
        }

        return 1;
    }

    (*root)->height = bigger(nodeHeight(&(*root)->left),nodeHeight(&(*root)->right)) +1;
    return response;
}
// ----------------------------------------------------------------------

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
int bigger(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
// ----------------------------------------------------------------------
Node* minimum(Node* current){
    Node *parent = current;
    while( current != NULL){
        parent = current;
        current = &(*current)->left;
    }
    return parent;
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
int findNode(Node* root,Person *person){
    if(isEmpty(root)){
        return -1;
    } else{
        Node *current = root;
        while (current!=NULL){
            if(isEquals(person,&(*current)->information)){
                return 1; //TODO print information
            }
            if( (*person)->id > (*current)->information->id){
                *current = (*current)->right;
            }else{
                *current = (*current)->left;
            }
        }
        return 0;
    }
}
// ----------------------------------------------------------------------
int isEquals(Person *this, Person *other){
    if((*this)->id == (*other)->id && (*this)->name == (*other)->name){
        return 1;
    }else{
        return 0;
    }
}

// ----------------------------------------------------------------------
void simpleRightRotation(Node * this){
    Node * other;
    *other = (*this)->right;
    (*this)->right = (*other)->left;
    (*other)->left = *this;
    (*this)->height = bigger(nodeHeight(&(*this)->left),nodeHeight(&(*this)->right) +1);

    (*other)->height = bigger(nodeHeight(&(*other)->left),(*this)->height +1);
}

// ----------------------------------------------------------------------
void simpleLeftRotation(Node * this){
    Node * other;
    *other = (*this)->left;
    (*this)->left = (*other)->right;
    (*other)->right = *this;
    (*this)->height = bigger(nodeHeight(&(*this)->left),nodeHeight(&(*this)->right) + 1);

    (*other)->height = bigger(nodeHeight(&(*other)->left),(*this)->height + 1);
}
// ----------------------------------------------------------------------
void doubleRightRotation(Node * this){
    simpleRightRotation(this);
    simpleLeftRotation(this);
}
// ----------------------------------------------------------------------
void dualRotationLeft(Node * this){
    simpleLeftRotation(this);
    simpleRightRotation(this);
}

