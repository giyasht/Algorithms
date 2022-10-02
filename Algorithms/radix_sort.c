#include<stdio.h>

int largest(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}

void RadixSort(int a[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;
    large = largest(a, n);

    while(large > 0)
    {
        NOP++;
        large/=10;
    }
    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
        {
bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
bucket_count[remainder] += 1;
        }
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j <bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;

    }
}

int main()
{
    int n,i;

    printf("Enter the size of array:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nUnsorted array:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    RadixSort(arr,n);
    printf("\nSorted array:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
