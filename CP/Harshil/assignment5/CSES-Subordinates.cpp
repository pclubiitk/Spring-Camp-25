#include<bits/stdc++.h>
using namespace std;

void DFS(const vector<int> adj[],int node,vector<int> &inTime,vector<int> &outTime, int &time)
{
    inTime[node]=time++;
    for(auto it:adj[node])
    {
        DFS(adj,it,inTime,outTime,time);
    }
    outTime[node]=time++;
}


int main()
{
    int time=0;
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> subordinates(n+1,0);
    vector<int> inTime(n+1,0);
    vector<int> outTime(n+1,0);
    DFS(adj,1,inTime,outTime,time);
    for(int i=1;i<=n;i++)
    {
        subordinates[i]=(outTime[i]-inTime[i]-1)/2;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<subordinates[i]<<" ";
    }
}