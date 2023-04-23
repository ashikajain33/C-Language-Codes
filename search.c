#include<stdio.h>
int linearSearch()
{
	int n,i,key;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("enter the searching element: ");
	scanf("%d",&key);
	
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
		   printf("found key %d at location: %d\n",key,i+1);
	    }
	}
	return 0;
}

int binarySearch()
{
	int n,i,key,low,mid,high;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("The entered array should be sorted\n");
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the searching element: ");
	scanf("%d",&key);
	low = 0;
	high = n - 1;
	mid = (low+high)/2;
	while (low <= high) 
	{
		if(a[mid] < key)
			low = mid + 1;
		else if (a[mid] == key) 
		{
			printf("%d found at location %d\n", key, mid+1);
			break;
		}
		else
			high = mid - 1;
		mid = (low + high)/2;
	}
	if(low > high)
		printf("Not found! %d isn't present in the list\n", key);
	return 0;
}
main()
{
	int choice,res;
	for(;;)
	{
	printf("1:linear Search\n");
	printf("2:binary Search\n");
	printf("3.exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
		if(choice==1)
		{
			linearSearch();
		}
		else if(choice==2)
		{
			binarySearch();
		}
		else if(choice==3)
		{
		printf("Exit\n");
		break;
	    }
		else 
			printf("INVALID INPUT\n");
		}
		printf("ASHIKA JAIN\n 2101641520032\n CS-AI-2B\n ");
	return 0;
}
