/*
 * AVL_Tree.c
 *
 *  Created on: 4 de mar de 2018
 *      Author: Renan
 */

#include "AVL_Tree.h"

// ----------------------------------------------------------------------
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

int nodeHeight(Node* node) {
	if (node == NULL) {
		return -1;
	} else {
		return node->height;
	}
}

// ----------------------------------------------------------------------

int treeHeight(Node* root) {
	if (isEmpty(root)) {
		printf("Node currently empty");
		return 0;
	}
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
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
	return labs(getHeight(node->left) - getHeight(node->right));
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

	int left_total = nodesNumber(root->left);
	int right_total = nodesNumber(root->right);
	return (left_total + right_total);
}
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------

// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
