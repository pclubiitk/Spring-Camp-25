#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007

const int MAXN = 1e5 + 1;
vi adj[MAXN], t;
vector<bool> vis;

bool dfs(int v, int tt) {
    vis[v] = true;
    t[v] = tt;
    for (int u : adj[v]) {
        if (!vis[u]) {
            if (!dfs(u, 3 - tt)) return false;
        } else if (t[u] == t[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    fastio;    
    int n, m;
    cin >> n >> m;    
    t.resize(n + 1);
    vis.resize(n + 1, false);    
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    bool is = true;
    rep(i, 1, n + 1) {
        if (!vis[i]) {
            if (!dfs(i, 1)) {
                is = false;
                break;
            }
        }
    }    
    if (!is) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        rep(i, 1, n + 1) {
            cout << t[i] << " ";
        }
        cout << endl;
    }
}
