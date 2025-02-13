#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
int n=1;
vector<ll> visited(n+1,0);
vector<vector<ll>> adj(n+1);
stack<ll> order;
void f(stack<ll> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}
bool iscycle=false;
void dfs(int node){
    // f(order);
    // cout<<node<<" hh\n";
    if(visited[node]==1){iscycle=true;return;}
    if(visited[node]==2){return;}
    visited[node]=1;
    for(auto j:adj[node]){
        if(iscycle==true) return;
        dfs(j);
        if(iscycle==true) return;
    }
    if(iscycle==true) return;
    visited[node]=2;
    order.push(node);
}
void solve() {
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    visited.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(iscycle){
        cout<<"IMPOSSIBLE";return;
    }
    f(order);
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}