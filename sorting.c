#include<stdio.h>
//Insertion Sort
int insertionSort(int a[],int n)
{
	int i, j, key;
	for(i =1; i <n; i ++)
	{
		key = a[i];
		j = i-1;
		while( j>=0 && key < a[j] )
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
//Selection Sort
int selectionSort (int a[],int n)
{
	int i,j, min, temp;
	for(i =0; i < n; i++)
	{	
		min =i ;                  
		for(j=i+1; j < n;j++)
		{
			if(a[j] < a[min])         
				min = j;                  
		}
		temp = a[i];
		a[ i ] = a[min];
		a[min] = temp;
	}
}
//Bubble Sort
int bubbleSort(int a[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{
			int temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
	}
}
//Radix Sort
int radixSort(int a[],int n)
{
  int i, b[10], m = 0, exp = 1;
  for (i = 0; i < n;  i++) 
  {
  	if (a[i] > m)
  		m = a[i];
  }  
  while (m / exp >  0) 
  {
  	int box[10] = { 0 };
  	int e = exp%10;
  	for (i = 0; i <  n; i++)
  		box[a[i] / e]++;
  		
  	for (i = 1; i <  10; i++)
  		box[i] += box[i -  1];
  		
  	for (i = n - 1; i  >= 0; i--)
  		b[--box[a[i] / e]] = a[i];
  		
  	for (i = 0; i <  n; i++)
  		a[i] = b[i];
  	exp *= 10;
  }
}
//Counting Sort
int countingSort(int a[],int n)
{
  int i, output[10], max = a[0];
  for (i=1; i<n; i++) 
  {
    if (a[i] > max)
      max = a[i];
  }
  int c[10];
  for (i = 0; i <= max; ++i) 
    c[i] = 0;
  for (i = 0; i < n; i++) 
    c[a[i]]++;
  for (i = 1; i <= max; i++) 
    c[i] += c[i - 1];
  for ( i = n- 1; i >= 0; i--) 
  {
    output[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }
  for (i = 0; i <n; i++) 
    a[i] = output[i];
}
main()
{
	int size,i;
	printf("enter array size: ");
	scanf("%d",&size);
	int a[size];
	printf("enter array elements: ");
	for(i=0;i<size;i++)
	scanf("%d",&a[i]);
	int choice;
	for(;;)
	{
	printf("\n 1. for Selection Sort\n 2. for Bubble Sort\n 3. for Insertion Sort\n");
	printf(" 4. for Counting Sort \n 5. for Radix Sort\n 6. Exit\n Enter choice: ");
	scanf("%d",&choice);
	if(choice==1)
	{
	selectionSort(a,size);
	printf("After sorting the array:\n ");
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	}
	else if(choice==2)
	{
	bubbleSort(a,size);
	printf("After sorting the array:\n ");
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	}
	else if(choice==3)
	{
	insertionSort(a,size);
	printf("After sorting the array:\n ");
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	}
	else if(choice==4)
	{
	countingSort(a,size);
	printf("After sorting the array:\n ");
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	}
	else if(choice==5)
	{
	radixSort(a,size);
	printf("After sorting the array:\n ");
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	}
	else if(choice==6)
	{
		printf("Exit\n");
		break;
	}
	else
	printf("INVALID INPUT\n");	
    }
	return 0;
}
