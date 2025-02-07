#include <bits/stdc++.h>
#define ll long long
#define vpll vector<pair<ll,ll>>
#define vll vector<ll>
#define vdll vector<vector<ll>>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define pb push_back
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

vector<ll> adj[100009];
ll v[100009];
bool visited[100009];
ll n;ll m;
ll res = 0;
vll leafs;
void dfs(ll x, ll ct) {
    if (ct > m) return;

    visited[x] = true;
    bool alp = true;

    for (ll neighbor : adj[x]) {
        if (!visited[neighbor]) {
            alp = false;
            if (v[neighbor] == 1) dfs(neighbor, ct + 1);
            else dfs(neighbor, 0);
        }
    }

    if (alp)res++;
    // if(alp)leafs.pb(x);
}

int main() {
    FAST
    cin >> n >> m;
    
    for (ll i = 1; i <= n; i++) cin >> v[i];
    
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll inc= v[1];
    dfs(1, inc);cout << res << endl;;
    // for(auto x:leafs)cout<<x<<" ";

}
