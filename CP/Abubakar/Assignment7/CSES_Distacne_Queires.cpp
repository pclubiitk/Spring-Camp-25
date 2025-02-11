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
vdll adj;
vdll anc;
vll dist;

void bfs()
{
    queue<ll>q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                anc[u][0] = v;q.push(u);
            }
        }
    }
    for (int j = 1;j <= maxc;j++)
    {
        for (int i = 1;i <= n;i++)
        {
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}
ll lca(ll u, ll v) {
    if(dist[u] < dist[v]) swap(u, v);
    ll d = dist[u] - dist[v];
    for (int i = 0; i <= maxc; i++) {
        if(d & (1LL << i))
            u = anc[u][i];
    }
    if(u == v) return u;
    for (int i = maxc; i >= 0; i--) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
            if(v==anc[u][0])return v;
            if(u==anc[v][0])return u;
        }
    }
    return anc[u][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    ll m =n-1;
    adj.resize(n+1);
    maxc = ceil(log2(n));
    anc.assign(n+1, vll(maxc+1, 0));
    dist.assign(n+1, -1);
    while(m--){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    while(q--){
        ll u, v;
        cin >> u >> v;
        ll L = lca(u, v);
        // cout<<"LCA: "<<L<<endl;
        ll d = dist[u] + dist[v] - 2 * dist[L];
        cout << d << endl;
    }

}


