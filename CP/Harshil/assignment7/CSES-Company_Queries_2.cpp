#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

void DFS_rank(int node,vector<int> &rank, vector<vector<int>> &adj)
{
    for(auto child : adj[node])
    {
        rank[child] = rank[node] + 1;
        DFS_rank(child,rank,adj);
    }
    return;
}

int main()
{
    FAST_IO
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, 0);
    vector<vector<int>> adj(n+1);
    for(int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
    }
    vector<int> rank(n+1, -1);
    rank[1]=0;
    DFS_rank(1,rank, adj);
    
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << rank[i] << " ";
    // }
    // cout << "\n";

    vector<vector<int>> dp(n+1, vector<int>(20, 0));
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = parent[i];
    }
    for(int j = 1; j < 20; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(rank[a] < rank[b])
        {
            swap(a,b);
        }
        int k = rank[a] - rank[b];
        for(int i = 0; i < 20; i++)
        {
            if(k & (1 << i))
            {
                a = dp[a][i];
            }
        }
        if(a == b)
        {
            cout << a << "\n";
        }
        else
        {
            for(int i=0; i<20; i++)
            {
                if(dp[a][i] != dp[b][i])
                {
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }
            cout << parent[a] << "\n";
        }
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j < 20; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}