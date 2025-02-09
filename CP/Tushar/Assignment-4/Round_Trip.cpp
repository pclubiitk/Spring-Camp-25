#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
void f(queue<ll> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<< " hhh\n";
    return;
}
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    stack<ll> q;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}