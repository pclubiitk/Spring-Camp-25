#include <bits/stdc++.h>
using namespace std;
#define ll int
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
#define MOD 1000000007

ll n, q;
ll maxc;
ll timer;
vll tin, tout;
vdll adj;
vdll anc;
vll dp;
vll ps;

void dfs(ll v, ll p) {
    tin[v] = ++timer;
    anc[v][0] = p;
    for (int i = 1; i <= maxc; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }
    for (auto x : adj[v]) {
        if (x != p) {
            dfs(x, v);
        }
    }
    tout[v] = ++timer;
}

void dfsd(ll v, ll p)
{
    dp[v] = ps[v];
    for(auto x : adj[v])
    {
        if (x != p) {
                       dfsd(x, v);
            dp[v] += dp[x];
 
        }
    }
}

ll ancbool(ll u, ll v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

ll lca(ll u, ll v) {
    if (ancbool(u, v)) return u;
    if (ancbool(v, u)) return v;
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
    ps.assign(n + 1, 0); 
    dp.assign(n + 1, 0);
    dfs(u, u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    adj.resize(n + 1);
    ll m = n - 1;

    while(m--)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ms(1);

    while(q--)
    {
        ll l, r;
        cin >> l >> r;
    
        ll L = lca(l, r);
        ps[l]++;
        ps[r]++;
        ps[L]--;
        if (L != 1) ps[anc[L][0]]--;
    }

    dfsd(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
