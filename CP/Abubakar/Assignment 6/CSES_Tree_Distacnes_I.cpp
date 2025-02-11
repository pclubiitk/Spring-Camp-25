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

ll n;
vector<vll> adj;

vll bfs(ll x) {
    vll d(n + 1, -1);
    queue<ll> q;
    q.push(x);
    d[x] = 0;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

int main() {
    FAST;
    cin >> n;
    adj.resize(n + 1);

    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vll d1 = bfs(1);  
    ll end1 = max_element(all(d1)) - d1.begin();

    vll d2 = bfs(end1);
    ll end2 = max_element(all(d2)) - d2.begin();

    vll d3 = bfs(end2);

    for (ll i = 1; i <= n; i++) cout << max(d2[i], d3[i]) << " ";
    cout << endl;
}
//3 BFS