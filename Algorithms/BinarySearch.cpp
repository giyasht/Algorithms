#include<bits/stdc++.h>
using namespace std;

int binarysearch(int a[],int n,int k){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;  
        if(a[mid]==k) return mid;

        else if(a[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}



int main(){
    int n,key;
    cin>>n>>key;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int i = binarysearch(a,n,key);
    if(i==-1){
        cout<<"Key not found";
    }
    else{
        cout<<"Key found at index : "<<i;
    }
}
