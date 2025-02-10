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
    vector<ll> cat(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> dist(n+1,0);
    if(cat[1]==1){
        dist[1]=1;
    }
    queue<ll> q;
    q.push(1);
    ll ans=0;
    ll idx=0;
    vector<bool> visited(n+1,0);
    visited[1]=1;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        ll oo=0;
        for(auto &k:adj[node]){
            // f(q);
            if(!visited[k]){
                oo++;
                if(dist[node]>=m && cat[k]==1){
                    // cout<<k<<" lll\n";
                    continue;
                }
                // cout<<k<<" pp\n";
                if(cat[k]==1){
                    dist[k]=dist[node]+1;
                }
                else{dist[k]=0;}
                q.push(k);
            }
            visited[node]=1;
        }
        if(oo==0){ans++;}
    }
    // for(auto k:dist){
    //     cout<<k<<" ";
    // }
    // cout<<"\n";
    cout<<ans<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}