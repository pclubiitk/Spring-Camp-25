#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i, t, n) for (int i = t; i < n; i++)

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    f(i,0,m) {  
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dis(n + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        ll node = cur.second;
        ll distance = cur.first;

        if (distance > dis[node]) 
            continue;

        for (auto child : adj[node]) {
            ll child_node = child.first;
            ll distance2 = child.second;

            if (distance + distance2 < dis[child_node]){
                dis[child_node] = distance + distance2;
                pq.push({dis[child_node], child_node});
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        cout << (dis[i] == 1e18 ? -1 : dis[i]) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}
