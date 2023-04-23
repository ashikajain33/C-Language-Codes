#include<stdio.h>
//Quicksort Function
int partition(int arr[],int low,int high)
{
	int pivot,i,j,temp;
	pivot = arr[high], i=low-1;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{ 
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}

int quicksort(int arr[],int low,int high)
{
	int pi,i;
	if(low<high)
	{
	    pi= partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
//Merge Sort
merge(int arr[], int low, int mid, int high) 
{
    int n1 = mid - low + 1 ,n2 = high - mid, i, j, k;
    int L[n1], M[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = low;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= M[j]) 
            arr[k++] = L[i++];
		 else 
            arr[k++] = M[j++];
    }
    while (i < n1) 
        arr[k++] = L[i++];

    while (j < n2) 
        arr[k++] = M[j++];
}
mergesort(int arr[], int low, int high) 
{
  if (low < high) 
  {
    int mid = (low + high ) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

main()
{
    int i,N,low,high,choice;
    printf("Enter number of elements:");
    scanf("%d",&N);
    int arr[N];
    printf("Enter the elements of an array:");
    for(i=0;i<N;i++)
    scanf("%d",&arr[i]);
    low=0, high=N-1;
	for(;;)
	{
	printf("        SORTING OF ELEMENTS\n");
	printf("        1.Sort Array by Quick Sort\n");
	printf("        2.Sort Array by Merge Sort\n");
	printf("        3.Exit\n");
	printf("        Enter choice:");
	scanf("%d",&choice);
	if(choice==1)
	{
	quicksort(arr,low,high);
	printf("The Sorted array is:\n");
   for(i=0;i<N;i++)
   printf("%d ",arr[i]);
    }
	else if(choice==2)
	{
	mergesort(arr,low,high);
	printf("The Sorted array is:\n");
	for (int i = 0; i < N; i++)
    printf("%d ", arr[i]);
    }
	else if(choice==3)
	{
	printf("Exit\n");
	break;
    }
	else
	printf("Invalid Choice\n"); 
}    
   printf("ASHIKA JAIN\n 2101641520032\n CS-AI-2B\n");
}
