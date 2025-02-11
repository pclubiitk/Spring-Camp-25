#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    
    f(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]){
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    for (int u = n; u != -1; u = parent[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    for (int u : path) {
        cout << u << " ";
    }
    cout << endl;
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}

