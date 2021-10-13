
//    This is a program on the insertion sort. It's a sorting algorithm.
//    -----------Time complexity of the insertion sort algorithm----------
//           1. Best complexity: n
//           2. Average complexity: n^2
//           3. Worst complexity: n^2
//    -----------Space complexity of the insertion sort algorithm---------
//           1.Space complexity: 1


#include<bits/stdc++.h>
using namespace std;

// function to print the elements of the array
void display(int arr[], int n) {

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    printf("\n");
}

// function to sort the elements of the array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        
        int temp = arr[i];
        int j = i - 1;
        
        while (temp < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

int main() {

    int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nBefore Sort the array is :\n";
    display(arr,n);

    insertionSort(arr, n);

    cout<<"\nAfter Insertion Sort the array is :\n";
    display(arr,n);

    return 0;

}
