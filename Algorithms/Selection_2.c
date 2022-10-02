#include <stdio.h>

int select(int arr[], int n, int i)
{
	int min, min_index;
	min=arr[i];
	min_index=i;

	for(int j=i+1; j<n; j++)
	{
		if(arr[j]<min)
		{
			min=arr[j];
			min_index=j;
		}
	}
	return min_index;
}

void selection(int arr[], int n)
{
	int index, t;
	for(int i=0; i<n-1; i++)
	{
		index=select(arr,n,i);
		t=arr[i];
		arr[i]=arr[index];
		arr[index]=t;
	}
}

void display(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int A[]={14, 7, 10, 3, 21, 18, 15};
	int n=sizeof(A)/sizeof(int);
	display(A,n);
	selection(A, n);
	display(A,n);

	return 0;
}