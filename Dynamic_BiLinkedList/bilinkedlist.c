


#include"bilinkedlist.h"

U32 nodesNum= 0;



U8 addNode( struct Node **start, int data )
{
	U8 check= 0;
	struct Node *ptr= *start, *new_node= (struct Node*)malloc( sizeof(struct Node) );
	if( new_node )
	{
		check= 1;
		new_node->data= data;
		if(!*start)							// if it is the first node
		{
			*start= new_node;				// this statement must be in this position, order is must
			new_node->previous= *start;
			new_node->next= *start;
		}
		else
		{
			while(ptr->next != *start )		// false condition when ptr is going to reset the cycle
				ptr= ptr->next;
			ptr->next= new_node;
			new_node->previous= ptr;
			new_node->next= *start;
			(*start)->previous= new_node;
		}
		nodesNum++;
	}
    return check ;
}


Status searchNode( struct Node *start, struct Node **pData, int data )
{
	Status state= NODE_FOUND;		// initialed by node fund.
	struct Node *ptr= start;
	*pData= start;
	if(ptr)							// if cycle has at least one node
	{
		if( start->data != data)	// if the node is not the first node
		{
			ptr= ptr->next;
        	for( ; ptr != start ; ptr= ptr->next )
            	if(ptr->data == data)
                	break;
			*pData= ptr;
			if( ptr== start ) 		// if ptr reset again, then no matched data
			{
				state= NODE_NOT_FOUND;
				*pData= NULL;
			}
		}
	}
	else							// if false ptr then cycle is empty
	{
		state= CYCLE_EMPTY;
		*pData= NULL;
	}
	return state ;
}


Status changeNodeData( struct Node *start, int data, int newData )
{
	Status state ;
	struct Node *ptr= start ;
	state= searchNode(start, &ptr, data );
	if( state== NODE_FOUND )
		ptr->data= newData ;
	return state ;
}


Status deleteNode( struct Node **start, int data )
{
	Status state ;
	struct Node *ptr= *start ;
	state= searchNode(*start, &ptr, data );
	if( state== NODE_FOUND  )
	{
		if( ptr == *start )	*start= ptr->next;	// if it the first node, make the next one it the start of the cycle.
		(ptr->previous)->next= ptr->next;
		(ptr->next)->previous= ptr->previous;
		nodesNum--;
		if(!nodesNum)	*start= NULL;			// if it the only node, end the start by null.
		free(ptr);
	}
	return state ;
}



U8 deleteAll( struct Node **start )
{
	char check= 0;
	struct Node *ptr= *start;
    check= 1;
    while(ptr)
    {
		*start= (*start)->next;
        free(ptr);
		ptr= *start;
        nodesNum--;
    }
    *start= ptr;
	return check;
}



Status viewNode( struct Node *start, int data )
{
	Status state;
	struct Node *ptr= start;
	state= searchNode(start, &ptr, data);
	if( state == NODE_FOUND )
		printf("Node Data= %d\n", ptr->data );
	return state ;
}



U8 viewAll( struct Node *start )
{
	U8 check= 0;
	U16 count ;
	struct Node *ptr= start;
	if(ptr)
	{
		check= 1;
		count= 1;
		printf("===================(CYCLE)======================\n");
		printf("Node number(%d), node Data= %d\n",count++ , ptr->data );
		ptr= ptr->next;
		while(ptr!=start)
		{
			printf("Node number(%d), node Data= %d\n",count , ptr->data );
			ptr= ptr->next;
			count++;
		}
		printf("====================(END)=======================\n");
	}
	return check;
}













