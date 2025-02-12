#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 200005
#define f(i,t,n) for(int i = t; i < n;i++)

int dist[2][mod];
vector<int> adj[mod];

int dfs(int u, int p, int d, int i) {
    dist[i][u] = d;
    int opt = -1;
    for (int v : adj[u]) {
        if (v != p) {
            int x = dfs(v, u, d + 1, i);
            if (opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
        }
    }
    if(opt == -1) return u;
    else return opt;

}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int maxNode = dfs(0, 0, 0, 0);
    int maxNode2 = dfs(maxNode, maxNode, 0, 0);
    dfs(maxNode2, maxNode2, 0, 1);
    
    for (int i = 0; i < n; i++) {
        cout << max(dist[0][i], dist[1][i]) << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ll test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
