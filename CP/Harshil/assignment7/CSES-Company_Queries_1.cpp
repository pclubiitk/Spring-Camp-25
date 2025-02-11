#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, 0);
    for(int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }
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
        int x, k;
        cin >> x >> k;
        for(int i = 0; i < 20; i++)
        {
            if(k & (1 << i))
            {
                x = dp[x][i];
            }
        }
        if(x == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << x << endl;
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