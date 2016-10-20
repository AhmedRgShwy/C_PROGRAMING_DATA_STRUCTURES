

#include"dqueue.h"


struct Node *dqueue= NULL;
unsigned int top= 0;

U8 enqueue(int data)
{
	U8 check= 0;
	struct Node *ptr= dqueue, *new_node= (struct Node*)malloc( sizeof(struct Node) );
	
	if( new_node )
	{
		check= 1;
		new_node->data= data;
		if(!top) // first node in stack
		{
			new_node->next= dqueue;
			dqueue= new_node;
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



U8 dequeue(int *held_data)
{
	U8 check= 0;
	struct Node *temp= dqueue;
	if(top)
	{
		check= 1;
		*held_data= dqueue->data;
		dqueue= dqueue->next;
		free(temp);
		top--;
	}

	return check;
}


















