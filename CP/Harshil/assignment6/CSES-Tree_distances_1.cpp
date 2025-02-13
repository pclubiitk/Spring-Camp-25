#include<bits/stdc++.h>
using namespace std;

int find_diameter_node(int node,int n,vector<vector<int>>&adj,vector<int>&dist)
{
    queue<int>q;
    q.push(node);
    dist[node]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto x:adj[curr])
        {
            if(dist[x]==-1)
            {
                dist[x]=dist[curr]+1;
                q.push(x);
            }
        }
    }
    int max_dist=0;
    int max_node=node;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>max_dist)
        {
            max_dist=dist[i];
            max_node=i;
        }
    }
    return max_node;
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
    vector<int>distance1(n+1,-1);
    vector<int>distance2(n+1,-1);
    vector<int>distance3(n+1,-1);
    int diameter_node1=find_diameter_node(1,n,adj,distance1);
    int diameter_node2=find_diameter_node(diameter_node1,n,adj,distance2);
    int temp=find_diameter_node(diameter_node2,n,adj,distance3);

    // cout<<diameter_node1<<" "<<diameter_node2<<" "<<temp<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<max(distance2[i],distance3[i])<<" ";
    }
    
}