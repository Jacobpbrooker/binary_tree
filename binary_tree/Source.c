#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree.h"

int main(void)
{
	srand(clock());														// seed random
	int numberOfNodes = rand() % 5 + 5;									// random number of nodes between 5 and 10

	root tree = createNewNode();										// create the root of the tree

	for (int i = 0; i < numberOfNodes; i++)								// loop as many times as nodes created
	{
		insert(tree, createNewNode());									// insert a new node into the tree
	}

	displayTree(tree);													// display entire tree

	PTREENODE searchNode = search(tree, rand()% 100);					// search for value in tree

	if (searchNode == NULL)												// if search returned NULL print not found
		printf("Node not found\n");
	else
		displayNode(searchNode);										// else return search node

	printf("Tree height - %d\n", treeHeight(tree));						// height of tree
	printf("Number of Nodes - %d\n", countNodes(tree));					// number of nodes on tree

	exit(EXIT_SUCCESS);													// exit
}
