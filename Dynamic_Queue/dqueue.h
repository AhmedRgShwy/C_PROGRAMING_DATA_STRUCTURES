

#ifndef DQUEUE_H
#define OQUEUE_H

#include<stdlib.h>


struct Node{
	int data;
	struct Node *next;
	};

typedef unsigned char U8 ;

U8 enqueue(int data);
U8 dequeue(int *held_data);




#endif 
