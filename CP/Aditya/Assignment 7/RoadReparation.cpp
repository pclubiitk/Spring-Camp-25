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

struct DSU {
    vi p;
    int components;
public:
    DSU (int n) : p(n), components(n) {
        rep(i, 0, n) p[i] = i;
    }
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int a;
    int b;
    ll weight;
};
bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}
int main() {
    int n, m;
    ll ans = 0;
    int added = 0;
    cin >> n >> m;
    vector<Edge> edgelist(m);
    rep(i, 0, m) {
        cin >> edgelist[i].a >> edgelist[i].b >> edgelist[i].weight;
    }
    sort(all(edgelist), comp);
    DSU dsu(n);
    for (Edge e : edgelist) {
        if (dsu.unite(e.a-1, e.b-1)) {
            ans += e.weight;
            added++;
        }
    }
    if (added == n-1) cout << ans;
    else cout << "IMPOSSIBLE";
}
