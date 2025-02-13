#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>>
ll mod=1e9+7;
// ll n=1;
vector<int> parent(1,0);
vector<int> sizee(1,1);
vector<int> visited(1,0);
vector<vector<int>> adj(1);
void dfs(int node,vector<ll> &dist){
    if(visited[node]==1){return;}
    visited[node]=1;
    for(auto k:adj[node]){
        dist[k]=min(dist[k],dist[node]+1);
        dfs(k,dist);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
