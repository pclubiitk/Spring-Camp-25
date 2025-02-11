#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
const ll MOD = 1000000007;
ll n, m;
vector<vpll> adj;
vector<ll> dis;
void djikstra(ll v){
    dis[v] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, v});
    while(!q.empty()){
        ll weight, node; 
        auto x = q.top(); 
        weight=x.ff; 
        node=x.ss; 
        q.pop();
        if(weight!=dis[node]){continue;}
        for(auto &[w, y] : adj[node])
        {
            if(dis[node] + w < dis[y])
            { 
                dis[y] = dis[node] + w;
                q.push({dis[y], y});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    adj.resize(n+1); dis.resize(n+1, inf);
    while(m--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({w, b});
    }
    djikstra(1);
    for(ll i = 1; i <= n; ++i){
        cout << dis[i] << " ";
    }
    cout<<endl;
    return 0;
}