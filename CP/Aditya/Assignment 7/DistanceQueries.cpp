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

vector<vi> ancestor(MAX, vi(21));
vector<vi> adj(MAX);
vi dep(MAX);
void preprocess(int node, int p) {
    ancestor[node][0] = p;
    rep(i, 1, 21) {
        if (ancestor[node][i-1] != -1) {
            ancestor[node][i] = ancestor[ancestor[node][i-1]][i-1];
        } else {
            ancestor[node][i] = -1;
        }
    }
    for (auto ch : adj[node]) {
        if (ch != p) {
            preprocess(ch, node);
        }
    }
}

void dfs(int x, int p, int d) {
    dep[x] = d;
    for (int k : adj[x]) {
        if (k != p) {
            dfs(k, x, d+1);
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    rep(i, 0, 21) {
        if ((dep[b]-dep[a])&(1<<i)) {
            b = ancestor[b][i];
        }
    }
    if (a == b) return a;
    for (int i = 20; i >= 0; i--) {
        if (ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    preprocess(1, -1);
    dfs(1, -1, 0);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dep[a] + dep[b] - 2*dep[lca(a, b)] << "\n";
    }
    
    return 0;
}
