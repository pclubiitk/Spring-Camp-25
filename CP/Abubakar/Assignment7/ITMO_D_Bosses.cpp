#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);

ll n, m;
vll parent, sized;
ll par(ll x) {
    if (parent[x] == x) return x;
    ll boss = par(parent[x]);
    sized[x] += sized[parent[x]]; 
    return parent[x] = boss;
}

void uni(ll x, ll y) {
    parent[x] = y;
    sized[x] = sized[y] + 1;
}

int main() {
    FAST;
    cin >> n >> m;

    parent.resize(n + 1);
    sized.resize(n + 1, 0);

    for (ll i = 1; i <= n; i++) parent[i] = i;

    while (m--) {
        ll a, u, v;
        cin >> a;
        if (a == 1) {
            cin >> u >> v;
            uni(u, v);
        } else {
            cin >> u;
            par(u); 
            cout << sized[u] <<endl;
        }
    }

}
