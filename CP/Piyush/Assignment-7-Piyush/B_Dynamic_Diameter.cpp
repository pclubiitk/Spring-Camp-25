#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int bfs(int begin,int n,int& farmost)
{
    vector<int> vis(n+1,-1);
    queue<int> q;
    q.push(begin);
    vis[begin]=0;
    int max_d=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(vis[v]==-1)
            {
                vis[v]=vis[u]+1;
                q.push(v);
                if(vis[v]>max_d)
                {
                    max_d=vis[v];
                    farmost=v;
                }
            }
        }

    }
    return max_d;

}
void distance(int begin,int n,vector<int>& dis)
{
    
    queue<int> q;
    q.push(begin);
    dis[begin]=0;
    while(!q.empty())
    {
        int m=q.front();
        q.pop();
        for(int v:adj[m]){
            dis[v]=dis[m]+1;
            q.push(v);

        }
    }

}
int main()
{
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int far_1=1;
    int dis_1=bfs(1,n,far_1);
    int far_2=1;
    int dia=bfs(far_1,n,far_2);
    vector<int> dist_f1,dist_f2;
    distance(far_1,n,dist_f1);distance(far_2,n,dist_f2);
    for(int i=1;i<=n;i++)
    {
        int temp=max(dist_f1[i],dist_f2[i]);
        int res=max(dia,temp+1);
        cout<<res<<endl;
    }


}