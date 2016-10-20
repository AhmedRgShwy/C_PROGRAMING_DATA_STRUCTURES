

#include"dstack.h"
#include<stdio.h>

extern unsigned long top;
int main(void)
{
	int data= 5;
	U8 check= 0;
	
	check= push(data);
	printf("push check= %d, push data= %d, top= %d\n", check, data, top);
	data= 6;
	check= push(data);
	printf("push check= %d, push data= %d, top= %d\n", check, data, top);
	data= 7;
	check= push(data);
	printf("push check= %d, push data= %d, top= %d\n", check, data, top);

	check= 0;
	data= 0;
	check= pop(&data);
	printf("pop check= %d, pop data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= pop(&data);
	printf("pop check= %d, pop data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= pop(&data);
	printf("pop check= %d, pop data= %d, top= %d\n", check, data, top);
	check= 0;
	data= 0;
	check= pop(&data);
	printf("pop check= %d, pop data= %d, top= %d\n", check, data, top);
	
	return 0;
}
