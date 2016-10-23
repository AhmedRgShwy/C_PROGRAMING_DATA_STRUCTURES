


/*************************************** Binsry Tree with small part and big part ******************************************/

#include"sbtree.h"
#include<stdio.h>


U8 addNode( struct Node **tree, int data )
{
	U8 check= 0, indicator= 0;
	struct Node *ptr= *tree, *new_node= (struct Node *) malloc( sizeof( struct Node));
	if( new_node )
	{
		check= 1;
		new_node->data= data;							// store the data in the new node.
		new_node->repeated= 1;							// number of repaeated is one.
		if( !*tree )									// if the tree in empty.
		{
			new_node->small= new_node->big= *tree;		// nulling the new node.
			*tree= new_node;							// makes tree point at the first node.
			
		}
		else											// if the tree is not empty.
		{
			while(ptr->small && ptr->big)				// search for the right null, or increment the repeated part
			{
				if( data < ptr->data )
					ptr= ptr->small;
				else if( data > ptr->data )
					ptr= ptr->big;
				else
					break;
			}
			if(  data < ptr->data )						// if the node will be added to small part.
			{
				new_node->small= new_node->big= ptr->small;
				ptr->small= new_node;
			}
			else if(  data > ptr->data )				// if the node will be added to big part.
			{
				new_node->small= new_node->big= ptr->big;
				ptr->big= new_node;
			}
			else										// repeated node
				ptr->repeated++ ;
		}
	}
	return check;
}



Status searchTree( struct Node *tree, struct Node **pData, struct Node **previous,int data )
{
	Status state= TREE_EMPTY;
	struct Node *ptr= tree;
	*pData= *previous= NULL;
	if( tree )
	{
		*previous= tree;
		if( ptr->data != data )			// if the data not the first node.
		{
			if( data < ptr->data )
				ptr= ptr->small;
			else if( data > ptr->data )
				ptr= ptr->big;
			while(ptr)					// search for the data.
			{
				if( data < ptr->data )
				{
					*previous= ptr;
					ptr= ptr->small;
				}
				else if( data > ptr->data )
				{
					*previous= ptr;
					ptr= ptr->big;
				}
				else
				{
					*pData= ptr;
					state= NODE_FOUND;
					break;
				}
			}
			if(!ptr)
				state= NODE_NOT_FOUND;
		}
		else
		{
			*pData= ptr;
			state= NODE_FOUND;
		}	
	}
	return state;
}



Status changeNodeData( struct Node *tree, int data, int newData)
{
	Status state;
	struct Node *ptr, *previous;
	state= searchTree(tree,&ptr, &previous,data);
	if( state == NODE_FOUND )
		ptr->data= newData;
	return state;
}



Status viewNode( struct Node *tree, int data )
{
	Status state;
	struct Node *ptr, *previous;
	state= searchTree(tree,&ptr,&previous,data);
	if(state== NODE_FOUND)
		printf("Node Data= %d, Repeated= %lu\n", ptr->data, ptr->repeated );
	return state;
}















