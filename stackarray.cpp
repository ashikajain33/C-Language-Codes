#include<stdio.h>
int top,s[100],max_size;
//traversal
int traverse()
{
	int i;
	if(top<=-1)
		printf("UNDERFLOW\n");
	else
	{
		printf("stack:\n");
		for(i=top;i>=0;i--)
			printf("%d\n",s[i]);
	}
}
//insertion
int PUSH(int item)
{
	if(top>=max_size-1)
		printf("OVERFLOW\n");
	else
	{
		top=top+1;
		s[top]=item;
	}
}
//deletion
int POP()
{
	if(top<=-1)
		printf("UNDERFLOW\n");
	else
	{
		printf("poped element: %d\n",s[top]);
		top=top-1;
	}
}
int main()
{
	top=-1;
	int choice,item;
	printf("Stack Operation from LinkedList\n");
	printf("1.PUSH \n2.POP\n3.Traverse\n4.Exit\n");
	printf("enter the size of stack:");
	scanf("%d",&max_size);
	for(;;)
	{
		printf("enter your choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter item to be inserted:");
			scanf("%d",&item);
			PUSH(item);
		}
		else if(choice==2)
			POP();
		else if(choice==3)
			traverse();
		else if(choice==4)
		{
			printf("Exit\n");
			break;
		}
		else
			printf("invalid choice\n");
	}
	printf("ASHIKA JAIN \n2101641520032 \nCS-AI-2B");
	return 0;
}
