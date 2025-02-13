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
ll ancbool(ll u, ll v)
{
    if(tin[u]<=tin[v]&&tout[u]>=tout[v])return 1;
    return 0;
}
ll lca(ll u, ll v)
{
    ll kuv = ancbool(u,v);
    ll kvu = ancbool(v,u);
    if(kuv==1)return u;
    if(kvu==1)return v;
    for(int i=maxc;i>=0;i--)
    {
        if(ancbool(anc[u][i],v)==0) u= anc[u][i];
    }
    u= anc[u][0];
    return u;
}
void ms(ll u) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    maxc = ceil(log2(n));
    anc.assign(n + 1, vll(maxc + 1));
    dfs(u, u-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    adj.resize(n + 1);


    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    
    ms(1);
    while (q--) {
        ll x, k;
        cin >> x >> k;

        for (int i = 0; i <= maxc; i++) {
            if (k & (1LL << i)) {
                x = anc[x][i];
                if (x == 0) break;
            }
        }
        cout << (x == 0 ? -1 : x) << endl;
    }
    
    return 0;
}
