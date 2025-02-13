#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1e9
#define MOD 1000000007
const int MAX = 200001;

vi adj[MAX], dist(MAX);
void dfs(int node, int parent) {
    for (auto child : adj[node]) {
        if (child != parent) {
            dist[child] = dist[node] + 1;
            dfs(child, node);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(n);
    vector<pi> edges(n-1);
    rep(i, 0, n-1) {
        cin >> edges[i].first >> edges[i].second;
    }
    for (auto edge : edges) {
        int a = edge.first, b = edge.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1, 0);
    int maxdist = 0, maxnode1 = 1, maxnode2 = 1;
    rep(i, 1, n+1) {
        if (dist[i] > maxdist) {
            maxdist = dist[i];
            maxnode1 = i;
        }
    }
    rep(i, 1, n+1) {
        dist[i] = 0;
    }
    dfs(maxnode1, 0);
    maxdist = 0;
    rep(i, 1, n+1) {
        if (dist[i] > maxdist) {
            maxdist = dist[i];
            maxnode2 = i;
        }
    }
    vi dist2 = dist;
    rep(i, 1, n+1) {
        dist[i] = 0;
    }
    dfs(maxnode2, 0);
    rep(i, 1, n+1) {
        int ans = max(dist2[i], dist[i]);
        cout << ans << " ";
    }
}
