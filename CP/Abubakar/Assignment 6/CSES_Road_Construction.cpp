#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
vll parent;
vll sized;

void ms(ll v) {
    parent[v] = v;
    sized[v] = 1;
}

ll par(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = par(parent[v]); 
}

void uni(ll v, ll w) {
    v = par(v), w = par(w);
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

    ll comp = n, sz = 1;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        
        if (par(a) != par(b)) comp--;
        uni(a, b);
        sz = max(sz, sized[par(a)]);
        
        cout << comp << " ";
        cout << sz << endl;
    }
}
