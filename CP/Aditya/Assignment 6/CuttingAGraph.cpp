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
const int MAX = 50001;

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
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            p[y] = x;
            components--;
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu(n);
    set<pi> edges;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (x > y) swap(x, y);
        edges.insert({x, y});
    }
    rep(i, 0, k) {
        int x, y; string op;
        cin >> op >> x >> y;
        x--; y--;
        if (x > y) swap(x, y);
        if (op == "cut") {
            edges.erase({x, y});
            dsu = DSU(n);
            tr(edge, edges) {
                dsu.unite(edge.first, edge.second);
            }
        } else {
            cout << ((dsu.connected(x, y)) ? "YES" : "NO") << endl;
        }
    }    
}
//WA