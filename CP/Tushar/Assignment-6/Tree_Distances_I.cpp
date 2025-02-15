
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dist(n+1,0);
    stack<ll> s;
    s.push(1);
    vector<ll> visited(n+1,0);
    ll node=0;
    ll maxx_dist=0;
    while(!s.empty()){
        ll u=s.top();
        s.pop();
        visited[u]=1;
        for(auto v:adj[u]){
            if(!visited[v]){
                s.push(v);
                dist[v]=dist[u]+1;
                if(maxx_dist<dist[v]){
                    maxx_dist=dist[v];
                    node=v;
                }
            }
        }
    }
    // cout<<node<<"\n";
    ll x=node;
    // for(auto k: dist){
    //     cout<<k<<" ";
    // }
    // cout<<" ll\n";
    s.push(node);
    visited.clear();
    visited.resize(n+1,0);
    node=0;
    maxx_dist=0;
    dist.clear();
    dist.resize(n+1,0);
    while(!s.empty()){
        ll u=s.top();
        s.pop();
        visited[u]=1;
        for(auto v:adj[u]){
            if(!visited[v]){
                s.push(v);
                dist[v]=dist[u]+1;
                if(maxx_dist<dist[v]){
                    maxx_dist=dist[v];
                    node=v;
                }
            }
        }
    }
    // for(auto k: dist){
    //     cout<<k<<" ";
    // }
    // cout<<" ll\n";
    // cout<<node<<"\n";
    ll y=node;
    vector<ll> dist_y(n+1,0);
    s.push(y);
    visited.clear();
    visited.resize(n+1,0);
    while(!s.empty()){
        ll u=s.top();
        s.pop();
        visited[u]=1;
        for(auto v:adj[u]){
            if(!visited[v]){
                s.push(v);
                dist_y[v]=dist_y[u]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]>dist_y[i]){cout<<dist[i]<<" ";}
        else{
            cout<<dist_y[i]<<" ";
        }
    }
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
