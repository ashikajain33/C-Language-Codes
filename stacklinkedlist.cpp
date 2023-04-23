#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* start=NULL;
void traverse()
{
	struct node *temp=start;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
		printf("\n");
}
void insert_beg(int n)		//push
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=n;
	p->next=NULL;
		if(start==NULL)
			start=p;
		else{
			p->next=start;
			start=p;
		}
	traverse();
}
void delete_beg()		//pop
{
	if(start!=NULL){
		start=start->next;
		printf("popped: %d",start->data);
	}
	else
	printf("linked list is empty\n");
	printf("\n");
}
main(){
	int item;
	printf("Stack Operation from Array\n");
	printf("1.push\n2.pop\n3.traverse\n4.To exit");
	for(;;){
		int ch;
		printf("\nEnter your choice:");
		scanf("%d",&ch);
			if(ch==1){
				printf("Enter Value to insert:");
				scanf("%d",&item);
				insert_beg(item);
					}
			else if(ch==2)
				delete_beg();
	        else if(ch==3)
				traverse();	
			else if(ch==4){
				printf("Exit\n");
				break;
				}
			else
				printf("Invalid Choice/n");
	}
return 0;
}
