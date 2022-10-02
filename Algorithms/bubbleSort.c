#include <stdio.h>

int main()
{
  int arr[] = {9,8,3,4,1,2,7,5,6};
  int n=sizeof(arr)/sizeof(arr[0]);

  printf("BUBBLE SORT\n\nArray before sorting is: ");
  for(int i=0;i<n;i++){
    printf(" %d ",arr[i]);
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }

  printf("\nArray after sorting is: ");
  for(int i=0;i<n;i++){
    printf(" %d ",arr[i]);
  }

  printf("\n");
}
