#include<bits/stdc++.h>
using namespace std;

int daimeter=INT_MIN;
void DFS(int node,int parent, vector<vector<int>>& adj,vector<int>&dp)
{
    if(dp[node]!=-1)
    {
        return;
    }
    int max1=-1,max2=-1;
    for(int i : adj[node] )
    {
        if(i==parent)
        {
            continue;
        }
        if(dp[i]==-1)
        {
            DFS(i,node,adj,dp);
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
    // if(adj[node].size()==1 && parent!=-1)
    // {
    //     dp[node]=0;
    //     daimeter=max(daimeter,dp[node]);
    //     return;
    // }
    dp[node]=max1+1;
    daimeter=max(daimeter,max1+max2+2);
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
    vector<int>dp(n+1,-1);
    DFS(1,-1,adj,dp);
    cout<<daimeter;
}