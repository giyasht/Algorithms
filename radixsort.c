#include<stdio.h>
#include<math.h>

int radixsort(int arr[], int size,int length)
{
    int range=10;
    int lcount=0;
    int ray=size;
    int outputarray[ray];
    for(int k=0;k<length;k++)
    {
    int indexarr[range];
    int cumalativesum[range];
    for(int i=0;i<range;i++)
    {
        indexarr[i]=0;
        cumalativesum[i]=0;
    }

    for(int i=0;i<size;i++)
    {
        int value=arr[i];
        int digit=value/(pow(10,lcount));
        int dig=digit%10;
        indexarr[dig]=indexarr[dig]+1;
    }

    

    for(int i=0;i<range;i++)
    {
        cumalativesum[i]=cumalativesum[i-1]+indexarr[i];
    }


    
    
    for(int i=ray-1;i>=0;i--)
    {
        int key=arr[i];
        int digit2=key/(pow(10,lcount));
        int dig2=digit2%10;
        int findex=cumalativesum[dig2];
        outputarray[findex-1]=key;
        --cumalativesum[dig2];
    }
    ++lcount;

    for(int i=0;i<size;i++)
    {
        arr[i]=outputarray[i];
    }
    
    }


    displayarray(outputarray,size);
}




















int displayarray(int arr[],int size)
{
    printf("the output array is\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}





void main()
{
    printf("enter size\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("enter elements\n");
    for(int i=0;i<size;i++)
    {
        int val;
        scanf("%04d",&val);
        arr[i]=val;
    }

    int length;

    printf("enter the max length\n");
    scanf("%d",&length);

    radixsort(arr , size,length);



}