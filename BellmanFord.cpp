#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mindist(vector<bool>vis,vector<int>dist,int n)
{
    int min=INT_MAX,node;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && dist[i]<min)
        {
            min=dist[i];
            node=i;
        }
    }
    return node;
}
void bellman(vector<vector<int> >v,int n,int src)
{
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    vector<bool>vis(n,false);
    dist[src]=0;
    for(int i=0;i<n;i++)
    {
        int u=mindist(vis,dist,n);
        vis[u]=true;
        for(int j=0;j<n;j++)
        {
            if(v[u][j] && (dist[u]+v[u][j])<dist[j])
            {
                dist[j]=dist[u]+v[u][j];
                parent[j]=u;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[j]!=INT_MAX && v[i][j] && vis[j] && dist[i]+v[i][j]<dist[j])
            {
                cout<<"negative cycle exists at vertices between "<<i+1<<"and"<<j+1;
                
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==src)
        {
            cout<<i+1<<":"<<dist[i]<<endl;
            continue;
        }
        cout<<i+1<<" ";
        int j=i;
        while(parent[j]!=src)
        {
            cout<<parent[j]+1<<" ";
            j=parent[j];
        }
        cout<<src+1<<":"<<dist[i]<<endl;

    }
}
int main()
{
     int n;
    cin>>n;
    vector<vector<int> > v;
    //int v[n][n+1];
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
            //cin>>v[i][j];
        }
        v.push_back(temp);
    }
    int src;
    cin>>src;
    bellman(v,n,src-1);
}
