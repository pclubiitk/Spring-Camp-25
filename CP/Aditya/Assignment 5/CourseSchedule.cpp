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
#define MODINV 500000004
 
vi solve(int n, vector<vi>& adj, vi& indeg) {
    queue<int> q;
    vi ans;
    rep(i, 1, n+1) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int child : adj[node]) {
            indeg[child]--;
            if (indeg[child] == 0) {
                q.push(child);
            }
        }
    }
    return ans;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n+1);
    vi indeg(n+1, 0);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    vi ans = solve(n, adj, indeg);
    if (sz(ans) != n) {
        cout << "IMPOSSIBLE";
    } else {
        tr(node, ans) {
            cout << node << " ";
        }
    }
    return 0;
}