

#include"bilinkedlist.h"

int main(void)
{
    struct Node *cycle= NULL ;
    int data, newData ;
    char ch, check;
    Status state;
    while(1)
    {
        printf("Enter choice:\n");
        printf("    a/A to add node.\n");
        printf("    d/D to delete node.\n");
        printf("    l/L to delete all nodes.\n");
        printf("    c/C to change node data.\n");
        printf("    v/V to view all nodes data.\n");
        printf("    t/T to terminate program.\n");
        printf("Your choice: ");
        scanf("%s", &ch);
        switch(ch)
        {
            case 'a': case 'A':
            printf("Enter node data: ");
            scanf("%d", &data);
            check= addNode(&cycle, data);
            if(!check)
                printf("There is no size.\n");
            else
                printf("Node has been added.\n");
            break;
            /**************************************/
            case 'd': case 'D':
            printf("Enter node data: ");
            scanf("%d", &data);
            state= deleteNode(&cycle,data);
			switch( state )
			{
            	case CYCLE_EMPTY:
                printf("Cycle is empty.\n");
				break;
            	case NODE_NOT_FOUND:
                printf("Node not found.\n");
				break;
            	default:
                printf("Node has been deleted.\n");
				break;
			}
            break;
            /***************************************/
            case 'c': case 'C':
            printf("Enter old node data: ");
            scanf("%d", &data);
            printf("Enter new node data: ");
            scanf("%d", &newData);
            state= changeNodeData(cycle,data,newData);
			switch( state )
			{
            	case CYCLE_EMPTY:
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
            case 'l': case 'L':
            check= deleteAll(&cycle);
            if(!check)
                printf("Cycle is empty.\n");
            else
                printf("Cycle has been deleted.\n");
            break;
            /****************************************/
            case 'v': case 'V':
            check= viewAll(cycle);
            if(!check)
                printf("Cycle is empty.\n");
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
        if( ch== 't' || ch== 'T')
            break;
    }
    return 0;
}



