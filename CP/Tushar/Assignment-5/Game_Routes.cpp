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
void f(stack<ll> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}
vector<ll> ways(n+1,-1);
ll dfs(int node){
    if(node==n){return 1;}
    else if(ways[n]!=-1){return ways[n];}
    ll wayys=0;
    for(auto next: adj[node]){
        wayys=(wayys+dfs(next))%mod;
    }
    return ways[node]=wayys;
}
void solve() {
    ll m;
    cin>>n>>m;
    adj.resize(n+1);
    ways.resize(n+1,-1);
    for(ll i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<dfs(1)<<"\n";
    return;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}