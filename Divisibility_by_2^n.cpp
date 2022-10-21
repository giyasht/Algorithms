#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
   int t;
   cin>>t;
   while(t--){
       int n ;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       int count2 = 0;
       for(int i=0;i<n;i++){
           while(arr[i]%2==0 && arr[i] > 1){
               arr[i] = arr[i]/2;
               count2++;
           }
       }
       if(count2 >= n){
           cout<<0<<endl;
       }
       else{
           vector<int> v2;
           int mul = 0;
           int j =0;
           for(int i=2;i<=n ;i++){
               int ind = i;
               int index2 = 0;
               while(ind%2==0 && ind > 1){
                   ind = ind/2;
                   index2++;
                   mul++;
               }
               v2.push_back(index2);
           }
           if((mul+count2) >= n){
               int ans =0;
               
               sort(v2.begin() , v2.end());
               reverse(v2.begin() , v2.end());
              for(auto x: v2){
                  ans++;
                  count2+=x;
                  if(count2 >= n){
                     break; 
                  }
              }
              cout<<ans<<endl;
           }
           else{
               cout<<-1<<endl;
           }
       }
   }
   return 0;
}
