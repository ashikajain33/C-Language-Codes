#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL, *r = NULL;
void enqueue(int d) //Insert elements in Queue
{
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
} 
void dequeue() // Delete an element from Queue
{
	struct node* t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
}
void print(){ // Print the elements of Queue
	struct node* t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("%d\n",t->data);
			t = t->next;
		}while(t != f);
		printf("\n");
	}
}
main()
{
	int i,n,choice; 
	printf("------------Operation For Circular Queue------------\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	for(;;)
	{
		printf("Enter the choice:");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter element:");
			scanf("%d",&n);
			enqueue(n);
		}
		else if(choice==2)
			dequeue();
		else if(choice==3)
			print();
		else if(choice==4){
			printf("Exit\n");
			break;
		}
		else
			printf("Invalid Input\n");
	}
}
