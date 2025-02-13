#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
#define MOD 1000000007

vll parent, sized;

void ms(ll v) {
    parent[v] = v;
    sized[v] = 1;
}

ll par(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = par(parent[v]);
}

void uni(ll v, ll w) {
    v = par(v);
    w = par(w);
    if (v != w) {
        if (sized[v] < sized[w]) swap(v, w);
        parent[w] = v;
        sized[v] += sized[w];
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    sized.resize(n + 1);
    
    for (ll i = 1; i <= n; i++) ms(i);

    while (m--) {
        string s;
        ll a, b;
        cin >> s >> a >> b;

        if (s == "union") uni(a, b);
        if (s == "get") cout << (par(a) == par(b) ? "YES" : "NO") << endl;
    }
}
