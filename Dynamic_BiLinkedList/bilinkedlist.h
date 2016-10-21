


#ifndef BILINKEDLIST_H
#define BILINKEDLIST_H
#include<stdio.h>
#include<stdlib.h>

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;


typedef enum{
	CYCLE_EMPTY,
	NODE_NOT_FOUND,
	NODE_FOUND
	}Status;


struct Node{
	int data;
	struct Node *next;
	struct Node *previous;
	};

/****************************************************************************
**  => FUNCTION FEATURES:												    *
** (1) this function adds one node at the end of the cycle.				    *
** (2) it returns true if it succeeded or zero if there is no heep size.	*
*****************************************************************************/
U8 addNode( struct Node **start, int data );


/************************************************************************************************************************
**  => FUNCTION FEATURES:																								*
** (1) this function searches for a specific node and hold it's address in pData argument, and also returns Status		*
** (2) It returns Satus of CYCLE_EMPTY, NODE_NOT_FOUND and NODE_FOUND.													*
** (3) if it did n't find the node, or the cycle is empty, then hold pointer pDatat will be NULL.						*
*************************************************************************************************************************/
Status searchNode( struct Node *start, struct Node **pData, int data );


/********************************************************************************************************************************
**  => FUNCTION FEATURES:																										*
** (1) this function use the function "searchNode" to find the node then change it's data.										*
** (2) it also returns status that has 4-probabilities of enum ( NODE_FOUND, NODE_NOT_FOUND, CYCLE_EMPTY).						*
*********************************************************************************************************************************/
Status changeNodeData( struct Node *start, int data, int newData );


/********************************************************************************************************************************
**  => FUNCTION FEATURES:																										*
** (1) this function use the function "searchNode" to find the node then delete it.												*
** (2) it also returns status that has 4-probabilities of enum ( NODE_FOUND, NODE_NOT_FOUND, CYCLE_EMPTY).						*
*********************************************************************************************************************************/
Status deleteNode( struct Node **start, int data );


/****************************************************************************
**  => FUNCTION FEATURES:													*
** (1) this function frees All nodes pointers from first one to last one.	*
*****************************************************************************/
U8 deleteAll( struct Node **start );


/****************************************************************************
**  => FUNCTION FEATURES:													*
** (1) this function prints the desired node then returns true 				*
** (2) if it didn't find the node or the cycle is empty it returns false.	*
*****************************************************************************/
Status viewNode( struct Node *start, int data );


/****************************************************************
**  => FUNCTION FEATURES:										*
** (1) this function prints all nodes then returns true 		*
** (2) if it the cycle is empty it returns false.				*
*****************************************************************/
U8 viewAll( struct Node *start );

























#endif
