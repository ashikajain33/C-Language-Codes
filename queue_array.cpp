#include<stdio.h>
static int front=-1, rear=-1;
int max_size, queue[100];
//overflow
int is_full()
{
	if(rear>=max_size-1)
		return 1;
	return 0;
}
//underflow
int is_empty()
{
	if(front<=-1)
		return 1;
	return 0;	
}
//traversal
int traverse()
{
	int i=front;
	while(i<=rear)
	{
		printf("%d ",queue[i]);
		i+=1;
	}
	printf("\n");
	return 0;
}
//insertion
int enqueue(int item)
{
	if(is_full())
		printf("overflow\n");
	else
	{
		if(front==-1 && rear==-1)
			front=rear=0;
		else
			rear=rear+1;
		queue[rear]=item;
//		traverse();
	}
	return 0;
}
//deletion
int dequeue()
{
	int del;
	if(is_empty())
		printf("underflow\n");
	else
	{
		del=queue[front];
		if(rear==front)
			front=rear=-1;
		else
			front=front+1;
		printf("deleting: %d",del);
	}
	printf("\n");
	return 0;
}
int main()
{
	int ele, choice;
	printf("enter the size of Queue:");
	scanf("%d",&max_size);
	printf("1.Enqueue\n2.Dequeue\n3.display\n4.Exit\n");
	for(;;)
	{
		printf("enter choice:");
		scanf("%d",&choice);
		if(choice==1)
		{		
			printf("enter element:");
			scanf("%d",&ele);
			enqueue(ele);
		}
		else if(choice==2)
			dequeue();
		else if(choice==3)
			traverse();
		else if(choice==4)
		    {
		    	printf("Exit\n");
		    	break;
			}
		else
		printf("Invalid Input\n");
	}
	return 0;
}
