

#ifndef SB_TREE_H
#define SB_TREE_H

#include<stdlib.h>

typedef unsigned char U8;
typedef unsigned long U32;
typedef enum{
	TREE_EMPTY,
	NODE_FOUND,
	NODE_NOT_FOUND
	}Status;

struct Node {
	int data;
	U32 repeated;
	struct Node *big;
	struct Node *small;
	};

U8 addNode( struct Node **tree, int data );
Status searchTree( struct Node *tree, struct Node **pData, struct Node **pPrevious,int data );
Status changeNodeData( struct Node *tree, int data, int newData);
Status viewNode( struct Node *tree, int data );





#endif
