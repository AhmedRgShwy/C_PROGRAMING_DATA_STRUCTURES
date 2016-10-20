


#include<stdio.h>
#include"queue.h"

int top;

int main(void)
{
	U8 check= 0;
	int data= 5;
	check= enqueue(data);
	printf("enqueue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 6;
	check= enqueue(data);
	printf("enqueue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 7;
	check= enqueue(data);
	printf("enqueue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 8;
	check= enqueue(data);
	printf("enqueue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 9;
	check= enqueue(data);
	printf("enqueue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	check= 0;
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	data= 0;
	check= dequeue(&data);
	printf("dequeue fun_check= %d, top= %d\nData= %d\n", check, top, data);
	
 return 0;
}
