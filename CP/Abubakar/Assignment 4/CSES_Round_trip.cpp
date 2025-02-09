#include <bits/stdc++.h>
#define ll long long
#define vpll vector<pair<ll,ll>>
#define vll vector<ll>
#define vdll vector<vector<ll>>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

ll n, m, tar;
vdll adj;
vll v, vis;

ll dfs(ll p, ll c) {
    if (vis[p] != -1) {
        tar = p;
        v.pb(p);
        return 1;
    }
    vis[p] = 1;
    for (ll x : adj[p]) {
        if (x == c) continue;
        ll y = dfs(x, p);
        if (y == 1) {
            v.pb(p);
            if(tar==p)return 2;
            else return 1;
        } 
        if (y == 2) return 2;
    }
    vis[p] = 2;
    return 0;
}

int main() {
    FAST;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, -1);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool alp=false;
    for (ll i = 1; i <= n; i++) {
        if (vis[i] == -1 && dfs(i, -1) == 2) {
            cout << v.size() << endl;
            for (ll x : v) cout << x << " ";
            alp=true;
            break;
           
        }
    }
    if(!alp)cout << "IMPOSSIBLE"<<endl;
    
}
