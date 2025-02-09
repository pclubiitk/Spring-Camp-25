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

vll parent;vll sized;
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
    ll n, m, k;
    cin >> n >> m >> k;
    
    parent.resize(n + 1);
    sized.resize(n + 1);
    for (ll i = 1; i <= n; i++) ms(i);
map<pll, bool> mp;
vector<tuple<string, ll, ll>> q;
vector<string> res;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        mp[{l, r}] = mp[{r, l}] = true;
    }

    while (k--) {
        string s;
        ll a, b;
        cin >> s >> a >> b;
        q.pb({s, a, b});
        if (s == "cut") mp[{a, b}] = mp[{b, a}] = false;
    }

    for (auto &x : mp) {
        if (x.ss) uni(x.ff.ff, x.ff.ss);
    }

    for (int i = q.size() - 1; i >= 0; i--) {
        if (get<0>(q[i]) == "ask") {
            res.pb(par(get<1>(q[i])) == par(get<2>(q[i])) ? "YES" : "NO");
        } else {
            uni(get<1>(q[i]), get<2>(q[i]));
        }
    }

    reverse(all(res));
    for (auto s: res) cout << s << endl;
}
