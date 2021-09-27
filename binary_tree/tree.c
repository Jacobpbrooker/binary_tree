#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void displayTree(PTREENODE node)
{
	if (node == NULL)													// exit condition
		return;
	displayTree(node->pLeft);											// call left
	displayNode(node);													// display node
	displayTree(node->pRight);											// call right
	return;
}

void displayNode(PTREENODE node)
{
	printf("Node Value = %d\n", node->data);							// display node
}

PTREENODE createNewNode(void)
{
	PTREENODE newNode = (PTREENODE)malloc(sizeof(TREENODE));			// create a new node and malloc
	
	if (!newNode)
	{
		fprintf(stderr, "Failed to malloc newNode\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = rand() % 100;										// random number generator of data
	newNode->pLeft = NULL;												// set left
	newNode->pRight = NULL;												// set right to null
	return newNode;
}


void insert(PTREENODE currentNode, PTREENODE newNode)
{
	if (newNode->data < currentNode->data)								// is newNode data less than current node?
	{
		if (currentNode->pLeft == NULL)									// is the pointer to left of node empty?
			currentNode->pLeft = newNode;								// if it is then attach newNode to left of currentNode
		else
			insert(currentNode->pLeft, newNode);						// else call again with node to the left
	}
	else if (newNode->data > currentNode->data)							// is newNode data greater than current node?
	{
		if (currentNode->pRight == NULL)								// is the pointer to right of node empty?
			currentNode->pRight = newNode;								// attach newNode to right of node
		else
			insert(currentNode->pRight, newNode);						// else call again with node to the right
	}
}

PTREENODE search(PTREENODE node, int searchNode)
{
	if (node == NULL) 
		return NULL;													// exit condition, search not found
	
	if (searchNode == node->data)										// search found, returning node
	{
		printf("Node searched %d, Node returned - ", searchNode);
		return node;
	}
	else if (searchNode < node->data)									// search int is lower than current node - move left
		search(node->pLeft, searchNode);
	else if (searchNode > node->data)									// search int is higher than current node - move right
		search(node->pRight, searchNode);

	
}

int countNodes(PTREENODE node)
{
	if (node == NULL)													// if node is NULL then there is no list and return 0
		return 0; 
	return(countNodes(node->pLeft) + countNodes(node->pRight) + 1);		// recursively count the number of nodes to the left and to the right
}

int treeHeight(PTREENODE node)
{
	int leftHeight = 0;
	int	rightHeight = 0; 
	int returnHeight = 0;

	if (node == NULL) 
		return returnHeight;											// no list, return 0
	
	leftHeight = treeHeight(node->pLeft);								// recursive call again left

	rightHeight = treeHeight(node->pRight);								// recursive call again right

	if (leftHeight > rightHeight)										// check which height is longer, left or right
		returnHeight = leftHeight + 1;									// return height of left, the +1 is to account for the head
	else
		returnHeight = rightHeight + 1;									// return height of right the +1 is to account for the head
	
	return returnHeight;												// return the height of the tree
}