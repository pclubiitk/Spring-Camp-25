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

vi adj[MAX], deg(MAX);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(n);
    queue<int> q;
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    rep(i, 1, n+1) {
        if (deg[i] == 1) q.push(i);
    }
    int ans = 0;
    vector<bool> vis(n+1, false);
    while(!q.empty()) {
        int leaf = q.front();
        q.pop();
        if (vis[leaf]) continue;
        for (int parent : adj[leaf]) {
            if (!vis[parent]) {
                vis[parent] = true;
                vis[leaf] = true;
                ans++;
                deg[parent]--;
            }
            for (int neighbor : adj[parent]) {
                deg[neighbor]--;
                if (deg[neighbor] == 1) q.push(neighbor);
            }
            break;
        }
    }
    cout << ans << endl;
}

//WA