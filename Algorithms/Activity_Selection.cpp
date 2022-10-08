#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    int start;
    int finish;
};
bool comparisonf(Activity a1,Activity a2)
{
        return (a1.finish)<(a2.finish);
}
int main()
{
    int n;
    cin>>n;
    Activity a[n];  
    for(int i=0;i<n;i++)
    {
        cin>>a[i].start;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].finish;
    }
    sort(a,a+n,comparisonf);
    int k=0;
    cout<<"1";
    int c=1;
    for(int i=1;i<n;i++)
    {
        if((a[k].finish)<=(a[i].start))
        {
            c++;
            cout<<","<<i+1;
            k=i;;
        }
    }
    cout<<"\n";
    cout<<c<<endl;
}
