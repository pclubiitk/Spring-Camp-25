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
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
    v = par(v), w = par(w);
    if (v != w) {
        if (sized[v] < sized[w]) swap(v, w);
        parent[w] = v;
        sized[v] += sized[w];
    }
}

int main() {
    FAST
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        s='0'+s;
        t='0'+t;
        parent.assign(n + 1, 0);
        sized.assign(n + 1, 0);

        for (ll i = 1; i <= n; i++) ms(i);

        for (ll i = 1; i <= n; i++) {
            if (i + k <= n) uni(i, i + k);
            if (i + k + 1 <= n) uni(i, i + k + 1);
        }

        vector<string> vs(n + 1), vt(n + 1);

        for (int i = 1; i <= n; i++) {
            vs[par(i)].pb(s[i]);
            vt[par(i)].pb(t[i]);
        }

        bool alp = false;
        for (int i = 1; i <= n; i++) {
            sort(all(vs[i]));
            sort(all(vt[i]));
            if (vs[i] != vt[i]) alp = true;
        }

        if(alp)cout<<"NO"<<endl;
        if(!alp)cout<<"YES"<<endl;
    }
}
