#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>
ll mod=1e9+7;
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    pq.push({0,1,0});
    vector<ll> ans;
    
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