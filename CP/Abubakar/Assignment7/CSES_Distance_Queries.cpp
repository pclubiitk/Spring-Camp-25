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
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
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
    dfs(u, u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    ll m=n-1;
    adj.resize(n + 1);
    while(m--){
        ll l,r;
        cin>>l>>r;
 adj[l].pb(r);
 adj[r].pb(l);
    }
    ms(1);
    
    vector<ll> dist(n+1, -1);
    queue<ll> qu;
    dist[1] = 0;
    qu.push(1);
    while(!qu.empty()){
        ll v = qu.front();
        qu.pop();
        for(auto x: adj[v]){
            if(dist[x] == -1){
                dist[x] = dist[v] + 1;
                qu.push(x);
            }
        }
    }
    
    while(q--){
        ll u, v;
        cin >> u >> v;
        ll LCA = lca(u, v);
        ll d = dist[u] + dist[v] - 2 * dist[LCA];
        cout << d << endl;
    }

}
//tle on one case
