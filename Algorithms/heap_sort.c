#include <stdio.h>
#include <stdlib.h>

int i;
int temp;

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int heap[n];
    printf("Enter the elements of the array: ");
    for(i = 1 ; i <= n ; i++)
        scanf("%d",&heap[i]);
    Heapsort(heap,n);
    printf("Array after sorting is: ");
    for(i = 1 ; i <= n ; i++)
        printf("%d ",heap[i]);
}

void Reheapifydown(int heap[],int start,int finish)
{
    int lchild = 2*start;
    int rchild = lchild+1;
    if ( lchild <= finish )
    {
        int max = heap[lchild];
        int index = lchild;
        if ( rchild <= finish )
        {
            if( heap[rchild] > max )
            {
                max = heap[rchild];
                index = rchild;
            }
        }
        if( heap[start] < heap[index] )
        {
            temp = heap[start];
            heap[start] = heap[index];
            heap[index] = temp;
            Reheapifydown(heap,index,finish);
        }
    }
}

void Heapsort(int heap[],int n)
{
    Heapify(heap,n);
    for(int i = n ; i >= 1 ; i--)
    {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        Reheapifydown(heap,1,i-1);
    }
}

void Heapify(int heap[], int n)
{
    int index = n/2;
    for(i = index ; i >= 1 ; i--)
        Reheapifydown(heap,i,n);
}




