#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int arr[500],n,i;
	
	printf("Enter the numbber of elements: ");
	scanf("%d",&n);
	
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}