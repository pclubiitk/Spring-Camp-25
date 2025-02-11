#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long

int get_parent(int a,vector<int>& parent)
{
    if(parent[a]==a) return a;
    return parent[a]=get_parent(parent[a],parent);
}

void check(int a,int b,vector<int>& parent)
{
    if(get_parent(a,parent)==get_parent(b,parent))
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }
}

void make_connection(int a,int b,vector<int>& parent,vector<int>& size)
{
    int parent_a=get_parent(a,parent);
    int parent_b=get_parent(b,parent);
    if(parent_a!=parent_b)
    {
        if(size[parent_b]<size[parent_a]) swap(parent_a,parent_b);
        parent[parent_a]=parent_b;
        size[parent_b]+=size[parent_a];
    }
}   

int32_t main()
{
    fastio
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> size(n+1);
    vector<vector<pair<int,int>>> adj(n+1);
    int cost=0;
    int edges=0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=1;i<n+1;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        pq.push({c, {a, b}});
    }
    while(!pq.empty()&&edges<n-1)
    {
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        int temp=pq.top().first;
        pq.pop();
        if(get_parent(a,parent)==get_parent(b,parent)) continue;
        make_connection(a,b,parent,size);
        edges++;
        cost+=temp;
    }
    if(edges!=n-1) cout<<"IMPOSSIBLE\n";
    else cout<<cost<<"\n";

}