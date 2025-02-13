#include<bits/stdc++.h>
using namespace std;

int BFS(int node,int n,vector<vector<int>>&adj,vector<int>&dist,int even,int odd)
{
    queue<int>q;
    q.push(node);
    dist[node]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        if(dist[curr]%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        for(auto x:adj[curr])
        {
            if(dist[x]==-1)
            {
                dist[x]=dist[curr]+1;
                q.push(x);
            }
        }
    }

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
    int count_even=0;
    int count_odd=0;
}