#include<stdio.h>
static int front=-1, rear=-1;
int que[100], max_size;
int is_full()
{
	if((rear+1)%max_size==front)
		return 1;
	return 0;
}
int is_empty()
{
	if(front==rear==-1)
		return 1;
	return 0;
}
//traversal
int traverse()
{
	if(is_empty())
		printf("empty Queue\n");
	else
	{
		int i=front;
		while(i!=rear)
		{
			printf("%d ",que[i]);
			i=(i+1)%max_size;
		}
		printf("%d ",que[i]);
	}
	printf("\n");
	return 0;
}
//insertion
int cir_endueue(int item)
{
	if(is_full())
		printf("overflow/n");
	else
	{
		if(front==-1 && rear==-1)
			front=rear=0;
		else
			rear=(rear+1)%max_size;
		que[rear]=item;
	}
	traverse();
	return 0;
}
//deletion 
int cir_dequeue()
{
	int del;
	if(is_empty())
		printf("underflow\n");
	else
	{
		del=que[front];
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%max_size;
		printf("deleting: %d",del);
	}
	printf("\n");
	return 0;
}
int main()
{
	int choice,ele;
	printf("Enter the size: ");
	scanf("%d",&max_size);
	printf("1.Insertion\n2.Deletion\n3.Traversing\n4.Exit\n");
	for(;;){
		printf("Enter choice:");
		scanf("%d",&choice);
		if(choice==1){
				printf("Enter the element: ");
				scanf("%d",&ele);
				cir_endueue(ele);
			}
		else if(choice==2)
			cir_dequeue();
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
