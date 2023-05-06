#include<stdio.h>
#include<stdlib.h>
	struct node
	{
		struct node* prev;
		int data;
		struct node * next;
	};
	struct node *start =NULL;
//Traversing the Linked list
void traverse()
{
	struct node *temp=start;
	if(start==NULL)
		printf("linked list is empty\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp->prev=temp;
		temp=temp->next;
	}
		printf("\n");
}	
//Inserting element in the begining
void insert_beg(int n)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=n;
	p->next=NULL;
	p->prev=NULL;
		if(start==NULL)
			start=p;
		else
		{
			p->next=start;
			start=p;
			p->next->prev=p;
		}
		traverse();
}
//Inserting element at the ending
void insert_end(int n)
{
	struct node *p,*temp=start;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=n;
	p->next=NULL;
	p->prev=NULL;
		if(start==NULL)
			start=p;
		else
		{	p->prev=temp;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=p;
	 }
    traverse();
}
//Inserting element at the any position
void insert_any_loc(int n)
{
	struct node *ptr,*temp=start,*temp1;
	int  pos, c=0;
	printf("enter the position to insert new:");
	scanf("%d",&pos);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=n;
	ptr->next=NULL;
	if(pos==1)
	insert_beg(n);
	else{
	while(temp!=NULL)
	{
		c++;
		if(c==pos-1)
		{
		ptr->prev=temp;
		temp1=temp->next;
		temp->next=ptr;
		ptr->next=temp1;
		}
	temp=temp->next;
	}
	}
	traverse();
}
//deletion at begining
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
//deletion at end
void delete_end()
{
	struct node *temp;
			if(start==NULL)
			printf("Linked list id empty\n");
		else{
			temp=start;
			while(temp!=NULL)
			{
			if(temp->next->next==NULL){
				printf("deleteing: %d",temp->next->data);
				temp->next=NULL;
			}
			temp=temp->next;	
		}
			printf("\n");
		}
}
//deletion at any position
void delete_any_loc()
{
	struct node *t1,*temp=start;
	int pos,c=0;
	printf("enter the position to delete element: ");
	scanf("%d",&pos);
	while(temp!=NULL)
	{
		c++;
		if(pos-1==c)
		{
			t1=temp->next->next;
			temp->next=t1;
			printf("%d ",temp->prev->data);
		}
		temp=temp->next;
	}
		printf("\n");
}
//count number of nodes
int count_node(){
	int c=0;
        struct node *temp=start;
        while(temp!=NULL)
        {
            c+=1;
            temp=temp->next;
        }
        return c;
}
//searching of x
void search()
{
	int x;
	printf("enter searching element:");
	scanf("%d",&x);
	int c=1,flag=0;
	struct node* t=start;
	if(start==NULL)
		printf("underflow\n");
	else{
		while(t->next!=NULL)
		{
			if(t->data==x){
					flag=1;
					break;
				}
			else
				c++;
			t=t->next;
		}
	}
	if(flag==1)
		printf("%d found at %d\n",x,c);
	else
		printf("element not exist\n");
}
main()
{
	int i,n,choice;
	printf("Choose the Doubly linked list operation:");
	printf("\n1.Insertion at begining\n");
	printf("2.Insertion at ending\n");
	printf("3.Insertion at any position\n");
	printf("4.Deletion from begining\n");
	printf("5.Deletion from ending\n");
	printf("6.Deletion from any position\n");
	printf("7.Traversing\n8.searching\n9.count node\n10.Exit\n");
	for(;;)
	{
	printf("enter choice: ");
	scanf("%d",&choice);
	if(choice==1){
		printf("enter data:");
		scanf("%d",&n);
		insert_beg(n);
	}
	else if(choice==2)
	{
		printf("enter data:");
		scanf("%d",&n);
		insert_end(n);
	}
	else if (choice==3)
	{
		printf("enter data:");
		scanf("%d",&n);
       	insert_any_loc(n);
    }
    else if(choice==4)
		delete_beg();
	else if(choice==5)
		delete_end();
	else if(choice==6)
		delete_any_loc();
	else if(choice==7)
    	traverse();	
    else if(choice==8)
    	search();
    else if(choice==9)
    	printf("total nodes: %d\n",count_node());
    else if(choice==10){
    printf("Exit\n");
    break;
	}
	else
	printf("INVALID CHOICE\n");
	}
}
