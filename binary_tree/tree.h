#pragma once

// structure of a node
typedef struct treeNode {
	int data;
	struct treeNode* pLeft;
	struct treeNode* pRight;
}TREENODE, *PTREENODE;

// typedef for the head of the tree
typedef struct treeNode* root;

// display functions
void displayTree(PTREENODE);
void displayNode(PTREENODE);

// create, add, and search
PTREENODE createNewNode(void);
void insert(PTREENODE, PTREENODE);
PTREENODE search(PTREENODE, int);

// height and number of Nodes
int countNodes(PTREENODE);
int treeHeight(PTREENODE);