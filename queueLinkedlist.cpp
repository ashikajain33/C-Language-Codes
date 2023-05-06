#include<stdio.h>
#include<stdlib.h>
	struct node
	{
		int data;
		struct node * next;
	};
	struct node *start =NULL;
void traverse()
{
	struct node *temp=start;
	if(start==NULL)
		printf("linked list is empty\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
		printf("\n");
}
void insert_end(int n)
{
	struct node *p,*temp=start;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=n;
	p->next=NULL;
		if(start==NULL)
			start=p;
		else
		{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=p;
	 }
    traverse();
}
void delete_beg()
{
	struct node *temp=start,*t;
	if(start==NULL)
	printf("linked list is empty\n");
	else
	{
		t=start->next;
		printf("deleted: %d",temp->data);
		free(temp);
		start=t;
	}
	printf("\n");
}
main()
{
	int i,n,choice;
	printf("Choose the operation for Linear Queue:\n");
	printf("1.Insertion\n");
	printf("2.Deletion\n");
	printf("3.Traverse\n");
	printf("4.Exit\n");
	for(;;)
	{
		printf("Enter the choice:");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter element:");
			scanf("%d",&n);
			insert_end(n);
		}
		else if(choice==2)
			delete_beg();
		else if(choice==3)
			traverse();
		else if(choice==4){
			printf("Exit\n");
			break;
		}
		else
			printf("Invalid Input\n");
	}
}
