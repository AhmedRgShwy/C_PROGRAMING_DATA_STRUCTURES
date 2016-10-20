

#include"dqueue.h"
#include<stdio.h>


extern unsigned int top;

int main(void)
{
	int data= 5;
	U8 check= 0;
	
	check= enqueue(data);
	printf("enqueue check= %d, enqueue data= %d, top= %d\n", check, data, top);
	data= 6;
	check= enqueue(data);
	printf("enqueue check= %d, enqueue data= %d, top= %d\n", check, data, top);
	data= 7;
	check= enqueue(data);
	printf("enqueue check= %d, enqueue data= %d, top= %d\n", check, data, top);

	check= 0;
	data= 0;
	check= dequeue(&data);
	printf("dequeue check= %d, dequeue data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= dequeue(&data);
	printf("dequeue check= %d, dequeue data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= dequeue(&data);
	printf("dequeue check= %d, dequeue data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= dequeue(&data);
	printf("dequeue check= %d, dequeue data= %d, top= %d\n", check, data, top);
	
	
	return 0;
}
