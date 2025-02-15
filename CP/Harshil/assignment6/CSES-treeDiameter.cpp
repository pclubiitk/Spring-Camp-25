#include<bits/stdc++.h>
using namespace std;


void DFS(int node, int n, vector<vector<int>>& adj,vector<int>&dp)
{
    if(dp[node]!=-1)
    {
        return;
    }
    int max1=0,max2=0;
    for(int i : adj[node] )
    {
        if(dp[i]==-1)
        {
            DFS(i,n,adj,dp);
        }
        if(dp[i]>max1)
        {
            max2=max1;
            max1=dp[i];
        }
        else if(dp[i]>max2)
        {
            max2=dp[i];
        }
    }
    dp[node]=max1+max2+1;
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}