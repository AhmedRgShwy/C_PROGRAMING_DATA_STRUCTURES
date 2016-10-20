
#include"queue.h"

int queue[MAX_SIZE];

extern int top= -1;


U8 isEmpty()
{
	U8 check= 0;
	if(top== -1)
		check= 1;
	return check;
}

U8 isFull()
{
	U8 check= 0;
	if(top== MAX_SIZE-1)
		check= 1;
	return check;
}


U8 enqueue(int data)
{
	U8 check= 0;
	check= isFull();
	if(!check) // if is not full
	{
		check= 1;
		queue[++top]= data;
	}
	else
		check= 0;
	return check;
}


U8 dequeue(int *held_data)
{
	U8 check= 0;
	unsigned short i;
	check= isEmpty();
	if(!check) // if is not empty
	{
		check= 1;
		*held_data= queue[0];
		top--;
		for(i= 1 ; i<= top+1 ; i++ )
			queue[i-1]= queue[i];
	}
	else
		check= 0;
	return check;
}






