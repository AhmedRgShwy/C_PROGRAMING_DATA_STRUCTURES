

#ifndef DSTACK_H
#define DSTACK_H

#include<stdlib.h>
typedef unsigned char U8;

struct Node{
	int data;
	struct Node *next;
	};


/****************************************************************************
**  => FUNCTION FEATURES:												    *
** (1) this function adds one node at the end of the list.				    *
** (2) it returns true if it succeeded or zero if there is no heep size.	*
*****************************************************************************/
U8 addNode( struct Node **list, int data );
U8 isEmpty();
U8 push( int data );
U8 pop( int *poped_data );



#endif 
