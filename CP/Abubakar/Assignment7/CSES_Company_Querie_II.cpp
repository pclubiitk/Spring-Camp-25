#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define loop(i, n) for(int i = 0; i < n; i++)
#define one(i, n) for(int i = 1; i <= n; i++)
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007

ll n, q;
ll maxc;
ll timer;
vll tin, tout;
vdll adj;
vdll anc;

void dfs(ll v, ll p) {
    timer++;
    tin[v] = timer;
    anc[v][0] = p;
    
    for (int i = 1; i <= maxc; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }
    
    for (auto x : adj[v]) {
        if (x != p) {
            dfs(x, v);
        }
    }
    timer++;
    tout[v] = timer;
}

ll ancbool(ll u, ll v) {
    if(tin[u] <= tin[v] && tout[u] >= tout[v]) return 1;
    return 0;
}

ll lca(ll u, ll v) {
    if(tin[u] < tin[v]) swap(u, v);
    
    if(ancbool(u, v)) return v;
    
    for (int i = maxc; i >= 0; i--) {
        if (!ancbool(anc[u][i], v))
            u = anc[u][i];
    }
    return anc[u][0];
}

void ms(ll u) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    maxc = ceil(log2(n));
    anc.assign(n + 1, vll(maxc + 1));
    dfs(u, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    adj.resize(n + 1);
    
    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    
    ms(1);
    while (q--) {
        ll u, v;
        cin >> u >> v;
        ll LCA = lca(u, v);
        cout << LCA << endl;
    }

}
