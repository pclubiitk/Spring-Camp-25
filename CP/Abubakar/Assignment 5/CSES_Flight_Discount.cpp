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
ll n, m;
vector<vpll> adj;
/*
0: no coupon, 1:coupon
*/
ll dijkstra() {
    vector<vector<ll>> dis(n + 1, vector<ll>(2, inf)); 
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq; 

    dis[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cost, node, used] = pq.top();
        pq.pop();

        if (cost > dis[node][used]) continue;

        for (auto &[w, y] : adj[node]) {
            if (dis[node][used] + w < dis[y][used]) {
                dis[y][used] = dis[node][used] + w;
                pq.push({dis[y][used], y, used});
            }

            if (!used && dis[node][0] + (w / 2) < dis[y][1]) {
                dis[y][1] = dis[node][0] + (w / 2);
                pq.push({dis[y][1], y, 1});
            }
        }
    }

    return min(dis[n][0], dis[n][1]); 
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
    }

    cout << dijkstra() << endl;
    return 0;
}
