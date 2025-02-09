
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll n=1;
vector<vector<ll>> adj(n+1);
vector<ll> parent(n+1);
vector<ll> size(n+1,1);
ll mod=1e9+7;
ll get(int node){
    if(parent[node]==node) return node;
    return parent[node]=get(parent[node]);
}
ll groups=n;
ll max_size=1;
void unite(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b) return;
    groups--;
    if(size[a]>size[b]){swap(a,b);}
    parent[a]=b;
    size[b]+=size[a];
    max_size=max(max_size,size[b]);
}
void solve() {
    ll m;
    cin>>n>>m;
    adj.resize(n+1);
    parent.resize(n+1);
    size.resize(n+1,1);
    groups=n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        unite(u,v);
        cout<<groups<<" "<<max_size<<"\n";
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
