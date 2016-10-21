


#include"sbtree.h"
#include<stdio.h>


int main(void)
{	
	struct Node *tree= NULL ;
    int data, newData ;
    char ch, check= 0;
	Status state;
	while(1)
    {
        printf("Enter choice:\n");
        printf("    a/A to add node.\n");
        printf("    c/C to change node data.\n");
        printf("    v/V to view node data.\n");
        printf("    t/T to terminate program.\n");
        printf("Your choice: ");
        scanf("%s", &ch);
		switch(ch)
        {
            case 'a': case 'A':
            printf("Enter node data: ");
            scanf("%d", &data);
            check= addNode(&tree, data);
            if(!check)
                printf("There is no size.\n");
            else
                printf("Node has been added.\n");
            break;
			/**************************************/
			case 'c': case 'C':
            printf("Enter old node data: ");
            scanf("%d", &data);
            printf("Enter new node data: ");
            scanf("%d", &newData);
            state= changeNodeData(tree,data,newData);
			switch( state )
			{
            	case TREE_EMPTY:
                printf("Cycle is empty.\n");
				break;
            	case NODE_NOT_FOUND:
                printf("Node not found.\n");
				break;
            	default:
                printf("Node has been changed.\n");
				break;
			}  
            break;
            /****************************************/
			case 'v': case 'V':
			printf("Enter node data: ");
            scanf("%d", &data);
            state= viewNode(tree,data);
            switch( state )
			{
            	case TREE_EMPTY:
                printf("Tree is empty.\n");
				break;
            	case NODE_NOT_FOUND:
                printf("Node not found.\n");
				break;
            	default:
				break;
			} 
            break;
            /*****************************************/
			case 't': case 'T':
			printf("End program.\nPREPARED BY AHMED SHAARAWY\n");
			break;
			/*****************************************/
            default:
            printf("False choice.\n");
            break;
		}
		if( ch== 't' || ch== 'T' )	break;
		
	}
	
	return 0;
}

































