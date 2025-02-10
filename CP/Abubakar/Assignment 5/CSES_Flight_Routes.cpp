#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
const ll MOD = 1000000007;
ll n, m, k;
vector<vector<pll>> adj;

void djkistra() {
    vector<ll> vis(n + 1, 0);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({ 0, 1 });

    while (!q.empty() && vis[n] < k) {
        ll d = q.top().first, u = q.top().second;
        q.pop();

        vis[u]++;
        if (vis[u] > k) continue;
        if (u == n) cout << d << " ";


        for (auto& [w, v] : adj[u]) {
            q.push({ d + w, v });
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n + 1);

    while (m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({ w, b });
    }

    djkistra();
    return 0;
}
