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
vi dep(MAX), c(MAX, 0);

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

void dfs2(int x, int p) {
    for (int k : adj[x]) {
        if (k == p) continue;
        dfs2(k, x);
        c[x] += c[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);    
    int n, m;
    cin >> n >> m;    
    rep(i, 2, n+1) {
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }    
    preprocess(1, -1);
    dfs(1, -1, 0);    
    while (m--) {
        int a, b;
        cin >> a >> b;
        int x = lca(a, b);
        c[a]++; c[b]++; c[x]--;
        if (ancestor[x][0] != -1) {
            c[ancestor[x][0]]--;
        }
    }
    dfs2(1, 0);
    rep(i, 1, n+1) {
        cout << c[i] << " ";
    }    
}
