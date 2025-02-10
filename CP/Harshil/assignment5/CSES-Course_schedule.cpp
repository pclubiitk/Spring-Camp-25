#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<int> &state, vector<int> &topo, bool &cycle) 
{
    state[node] = 1; 
    for (int neighbor : adj[node]) 
    {
        if (state[neighbor] == 0) 
        {
            dfs(neighbor, adj, state, topo, cycle);
            if (cycle) return;
        } 
        else if (state[neighbor] == 1) 
        {
            // Cycle detected
            cycle = true;
            return;
        }
    }
    state[node] = 2;
    topo.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    vector<int> state(n+1, 0);
    vector<int> topo;
    bool cycle = false;
    
    for (int i = 1; i <= n; i++) 
    {
        if (state[i] == 0) 
        {
            dfs(i, adj, state, topo, cycle);
            if (cycle) break;
        }
    }
    
    if (cycle) 
    {
        cout << "IMPOSSIBLE" << endl;
    } 
    else 
    {
        reverse(topo.begin(), topo.end());
        for (int node : topo) 
        {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}