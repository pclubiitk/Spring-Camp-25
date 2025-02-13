#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> parent;
    vector<ll> exp;
    vector<ll> delta;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        exp.resize(n + 1, 0);
        delta.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            int orig_parent = parent[x];
            parent[x] = find(parent[x]);
            delta[x] += delta[orig_parent];
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;

        if (size[rx] < size[ry]) {
            swap(rx, ry);
        }
        parent[ry] = rx;
        delta[ry] = exp[ry] - exp[rx];
        size[rx] += size[ry];
    }

    void add(int x, ll v) {
        int root = find(x);
        exp[root] += v;
    }

    ll get(int x) {
        find(x);
        return exp[parent[x]] + delta[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        string s;
        cin >> s;
        if (s == "join") {
            int X, Y;
            cin >> X >> Y;
            dsu.unite(X, Y);
        } else if (s == "add") {
            int X, V;
            cin >> X >> V;
            dsu.add(X, V);
        } else if (s == "get") {
            int X;
            cin >> X;
            cout << dsu.get(X) << "\n";
        }
    }

    return 0;
}
