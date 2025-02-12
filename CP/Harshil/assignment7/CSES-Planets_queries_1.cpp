#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
    FAST_IO
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> parent[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(30, 0));
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = parent[i];
    }
    for(int j = 1; j < 30; j++)
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
        for(int i = 0; i < 30; i++)
        {
            if(k & (1 << i))
            {
                x = dp[x][i];
            }
        }
        cout << x << "\n";
    }

    // for(int i=0;i<n+1;i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
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