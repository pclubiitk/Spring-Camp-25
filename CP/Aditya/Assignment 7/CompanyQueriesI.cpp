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
int query(int node, int k) {
    if (k == 0) return node;
    if (node == -1) return -1;
    for (int i = 20; i >= 0; i--) {
        if (k&(1<<i)) {
            return query(ancestor[node][i], k-(1<<i));
        }
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    rep(i, 2, n+1) {
        cint(p);
        adj[p].push_back(i);
    }
    preprocess(1, -1);
    rep(i, 0, q) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
    }
}

//doubt:: what happens if we do preprocess(1, 1) or (1, 0)?