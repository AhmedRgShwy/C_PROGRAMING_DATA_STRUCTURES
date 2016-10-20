



#include"dstack.h"
#include<stdio.h>

unsigned long top= 0;

struct Node *dstack= NULL;


U8 push( int data )
{
	U8 check= 0;
	struct Node *ptr= dstack, *new_node= (struct Node*)malloc( sizeof(struct Node) );
	
	if( new_node )
	{
		check= 1;
		new_node->data= data;
		if(!top) // first node in stack
		{
			new_node->next= dstack;
			dstack= new_node;
		}
		else // is not first node in satck
		{
			for( ; ptr->next ; ptr= ptr->next );
			new_node->next= ptr->next;
			ptr->next= new_node;
		}
		top++;
	}
	return check;
}


U8 pop( int *poped_data )
{
	U8 check= 0;
	struct Node *instant= dstack, *previous= dstack;
	
	if(top) // if is not empty
	{
		check= 1;
		if(instant->next) // there are two nodes or more in the stack
		{
			instant= instant->next;
			while(instant->next)
			{
				previous= previous->next;
				instant= instant->next;
			}
			*poped_data= instant->data;
			previous->next= instant->next;
		}
		else // there is one node in the stack
		{
			*poped_data= instant->data;
			previous= previous->next;
		}
		free(instant);
		top--;
	}
	return check;
}











