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

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<bool> vis;
vector<int> p;
int in = -1, f = -1;

bool dfs(int v, int par) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (u == par) continue;
        if (vis[u]) {
            f = v;
            in = u;
            return true;
        }
        p[u] = v;
        if (dfs(u, p[u]))
            return true;
    }
    return false;
}

int main() {
    fastio;    
    int n, m;
    cin >> n >> m;    
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    vis.assign(n + 1, false);
    p.assign(n + 1, -1);    
    rep(i, 1, n + 1) {
        if (!vis[i] && dfs(i, -1)) break;
    }    
    if (in == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vi ans;
        ans.push_back(in);
        for (int v = f; v != in; v = p[v])
            ans.push_back(v);
        ans.push_back(in);
        
        cout << sz(ans) << endl;
        for (int v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }    
}
