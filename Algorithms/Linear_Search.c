#include <stdio.h> 

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    int x;
    int arr[] = { 7, 5, 49, 36, 4057 }; 
    //Input data form user that want to search in the above array
    printf("Enter the number : ");
    scanf("%d",&x);
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = search(arr, n, x); 
    if(result == -1) 
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n",result); 
    return 0; 
} 
