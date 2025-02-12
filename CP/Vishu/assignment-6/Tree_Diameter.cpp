#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n; i++)

vector<int> bfs(int start, vector<vector<int>> &adj, int &farthest_node) {
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> q;

    q.push(start);
    distance[start] = 0;
    farthest_node = start;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
                if (distance[neighbor] > distance[farthest_node]) {
                    farthest_node = neighbor;
                }
            }
        }
    }
    return distance;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    
    f(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int farthest_node;
    bfs(1, adj, farthest_node);

    int farthest_node2;
    vector<int> distances = bfs(farthest_node, adj, farthest_node2);
    int tree_diameter = *max_element(distances.begin(), distances.end());

    cout << tree_diameter << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}


