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
    ll n;
    cin>>n;
    vector<ll> dist(1,1e10);
    vector<ll> dist_2(1,1e10);
    adj.resize(n+1);
    visited.resize(n+1,0);
    dist.resize(n+1,1e10);
    dist_2.resize(n+1,1e10);
    vector<ll> dist_3(n+1,1e10);
    ll node_1=0;
    ll node_2=0;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n==1){cout<<1;return;}
    dist[1]=0;
    dfs(1,dist);
    visited.clear();
    visited.resize(n+1,0);
    ll maxx=0;
    for(int i=2;i<n+1;i++){
        if(dist[i]>maxx){maxx=dist[i];node_1=i;}
    }
    dist_2[node_1]=0;
    dfs(node_1,dist_2);
    visited.clear();
    visited.resize(n+1,0);
    maxx=0;
    for(int i=1;i<n+1;i++){
        // if(i==node_1){continue;}
        if(dist_2[i]>=maxx){maxx=dist_2[i];node_2=i;}
    }
    // cout<<node_1<<" "<<node_2<<" \n";
    dist_3[node_2]=0;
    dfs(node_2,dist_3);
    ll diameter=dist_3[node_1];
    visited.clear();
    visited.resize(n+1,0);
    for(int i=1;i<=n;i++){
        ll ff=dist_2[i];
        ll gg=dist_3[i];
        if(ff>=gg){
            cout<<max(ll(ff+1),diameter)<<"\n";
        }
        else{
            cout<<max(gg+1,diameter)<<"\n";
        }
    }
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
