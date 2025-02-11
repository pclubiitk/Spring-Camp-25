#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define loop(i, n) for(ll i = 0; i < n; i++)
#define one(i, n) for(ll i = 1; i <= n; i++)
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
ll n, m;
vector<tuple<ll, ll, ll>> edges;

vector<ll> parent, sized;
void ms(ll x) {
    parent[x] = x;
    sized[x] = 1;
}
ll par(ll x) {
    return parent[x] == x ? x : parent[x] = par(parent[x]);
}
void uni(ll x, ll y) {
    x = par(x), y = par(y);
    if (x != y) {
        if (sized[x] < sized[y]) swap(x, y);
        parent[y] = x;
        sized[x] += sized[y];
    }
}


int main()
{
    FAST;
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.pb({ w,u,v });
    }
    sort(all(edges));
    parent.resize(n + 1), sized.resize(n + 1);
    for (ll i = 1; i <= n; i++) ms(i);

    ll res = 0, ct = 0;
    for (auto [w, u, v] : edges) {
        if (par(u) != par(v)) { //*if not in diff comp*
            uni(u, v);
            res += w;
            ct++;
            if (ct == n - 1) break;
        }
    }
    if(ct!=n-1){cout<<"IMPOSSIBLE"<<endl;return 0;}
    cout << res << endl;
}
