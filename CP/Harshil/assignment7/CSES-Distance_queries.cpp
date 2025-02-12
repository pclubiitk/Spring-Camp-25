#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

void DFS_depth(int node, vector<int>& depth, vector<vector<int>>& adj) 
{
    for (auto child : adj[node]) 
    {
        depth[child] = depth[node] + 1;
        DFS_depth(child, depth, adj);
    }
}

int main()
{
    FAST_IO
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<bool> hasParent(n+1, false);
 
    for (int i = 0; i < n-1; i++) 
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        parent[b] = a;
        hasParent[b] = true;
    }
    
    int root = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (!hasParent[i]) 
        {
            root = i;
            break;
        }
    }
    
    vector<int> depth(n+1, -1);
    depth[root] = 0;
    DFS_depth(root, depth, adj);

    const int LOG = 20; 
    vector<vector<int>> dp(n+1, vector<int>(LOG, 0));
    for (int i = 1; i <= n; i++) 
    {
        dp[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }
    }
    
    while(q--) 
    {
        int a, b;
        cin >> a >> b;
        if(depth[a] < depth[b]) 
        {
            swap(a, b);
        }
        int diff = depth[a] - depth[b];
        int temp_a = a;
        int temp_b = b;
        for (int i = 0; i < LOG; i++) 
        {
            if(diff & (1 << i)) 
            {
                temp_a = dp[temp_a][i];
            }
        }
        
        if(temp_a == temp_b) 
        {
            cout << depth[a] + depth[b] - 2 * depth[temp_a] << "\n";
        }
        else 
        {
            for (int i = LOG-1; i >= 0; i--) 
            {
                if(dp[temp_a][i] != dp[temp_b][i]) 
                {
                    temp_a = dp[temp_a][i];
                    temp_b = dp[temp_b][i];
                }
            }   
            int lca = parent[temp_a];
            cout << depth[a] + depth[b] - 2 * depth[lca] << "\n";
        }
    }
    
    return 0;
}
