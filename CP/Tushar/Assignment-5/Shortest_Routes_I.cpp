#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>>;
ll mod=1e9+7;
ll n=1;
vector<vector<pair<ll,ll>>> adj;
vector<ll> visited(n+1,0);
void solve() {
    ll m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1,0);
    for(ll i=0;i<m;i++){
        ll a,b,c;   
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
    p.push({0,1});
    vector<ll> shortest(n+1,1000000000000000);
    // shortest[1]=0;
    while(!p.empty()){
        // print_queue(p);
        ll node=p.top().second;
        ll dist=p.top().first;
        p.pop();
        if(dist>shortest[node]){continue;}
        shortest[node]=dist;
        for(auto l:adj[node]){
            ll nextnode=l.first;
            ll weight=l.second;
            if(shortest[nextnode]>dist+weight){
                p.push({dist+weight,nextnode});
                shortest[nextnode]=dist+weight;
            }
        }
    }
    for(auto l=1;l<=n;l++) {
        cout<<shortest[l]<<" ";
    }
    cout<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}