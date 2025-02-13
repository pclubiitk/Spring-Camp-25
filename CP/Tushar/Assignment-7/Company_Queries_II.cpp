#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>>
ll mod=1e9+7;
vector<int> depth(1,0);
vector<int> visited(1,0);
vector<vector<int>> adj(1);
void dfs(int node){
    for(auto l:adj[node]){
        depth[l]=depth[node]+1;
        dfs(l);
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    adj.resize(n+1);
    depth.resize(n+1,0);
    depth[1]=0;
    vector<ll> parent;
    parent.push_back(0);
    parent.push_back(1);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        parent.push_back(x);
        adj[x].push_back(i+2);
    }
    ll z=log2(n)+1;
    parent[1]=0;
    parent[0]=0;
    dfs(1);
    vector<vector<ll>>up(n+1,vector<ll>(z+1));
    for(int i=1;i<n+1;i++){
        up[i][0]=parent[i];
    }
    for(int i=1;i<z;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
    for(auto k:up){
        for(auto o:k){
            cout<<o<<" ";
        }
        cout<<" \n";
    }
    for(auto k:depth){
        cout<<k<<" ";
    }
    cout<<" gg\n";
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(depth[x]<depth[y]){swap(x,y);}
        ll k=depth[x]-depth[y];
        ll node=x;
        for(int j=0;j<z;j++){
            if(k &(1<<j)){
                node=up[node][j];
            }
        }
        x=node;
        if(x==y){cout<<x<<"\n";continue;}
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
