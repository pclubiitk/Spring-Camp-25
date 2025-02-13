#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
ll n=1;
// int n=1;
vector<ll> visited(n+1,0);
vector<vector<ll>> adj(n+1);
// vector<ll> ways(n+1,-1);
vector<ll> ways(n+1,-1);
ll dfs(int node){
    if(node==n){return 1;}
    else if(ways[node]!=-1){return ways[node];}
    ll o=0;
    for(auto l:adj[node]){
        o=(o+dfs(l))%mod;
    }
    return ways[node]=o;
}
void solve() {
    ll m;
    cin>>n>>m;
    ways.resize(n+1,-1);
    visited.resize(n+1,0);
    adj.resize(n+1);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    ll ans=dfs(1);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}