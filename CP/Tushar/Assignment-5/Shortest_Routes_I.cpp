#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
ll n=1;
vector<ll> shortest(n+1,1e10);
vector<vector<pair<ll,ll>>> adj;
vector<ll> visited(n+1,0);
void f(priority_queue<pair<ll,ll>> s){
    cout<< " mm\n";
    while(!s.empty()){
        cout<<s.top().first<<" "<<s.top().second<<"\n";
        s.pop();
    }
    cout<< " kkk\n";
}
void solve() {
    ll m;
    cin>>n>>m;
    adj.resize(n+1);
    shortest.resize(n+1,1e10);
    shortest[1]=0;
    visited.resize(n+1,0);
    for(ll i=0;i<m;i++){
        ll a,b,c;   
        cin>>a>>b>>c;
        if(a==b){continue;}
        adj[a].push_back({b,c});
    }
    // priority_queue<pair<ll,ll>,greater<pair<ll,ll>>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0,1});
    while(!q.empty()){
        // f(q);
        ll d=q.top().first;
        ll node=q.top().second;
        q.pop();
        if(d>shortest[node]){continue;}
        for(auto l:adj[node]){
            ll nextnode=l.first;
            ll weight=l.second;
            if(shortest[node]+weight<shortest[nextnode]){
                shortest[nextnode]=shortest[node]+weight;
                q.push({shortest[nextnode],nextnode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<shortest[i]<<" ";
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