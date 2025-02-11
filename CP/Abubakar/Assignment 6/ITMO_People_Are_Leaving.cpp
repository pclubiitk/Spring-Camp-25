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

vll parent, sized;

void ms(ll v) {
    parent[v] = v;
    sized[v] = v;
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
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // gave tle without fastio WoW
    ll n, m;
    cin >> n >> m;
    parent.resize(n + 2);
    sized.resize(n + 2);
    for (ll i = 1; i <= n + 1; i++) ms(i);

    while (m--) {
        char c;
        ll l;
        cin >> c >> l;
        if (c == '-') uni(l, l + 1);
        if(c=='?'&&par(l)<=n)cout << par(l)<< endl;
        if(c=='?'&&par(l)>n)cout<<-1<<endl;
    }
}
