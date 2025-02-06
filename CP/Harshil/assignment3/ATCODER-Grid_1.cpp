#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    long long dp[h+1][w+1];
 
    for(int i = 0; i <= h; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)

        {
            cin >> grid[i][j];
        }
    }
    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++)
    //     {
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    dp[1][1] = (grid[0][0] == '.') ? 1 : 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '.')
            {
                dp[i+1][j+1] = (dp[i][j+1]+dp[i+1][j])%MOD;
            }
            else{
                dp[i+1][j+1] = 0;
            }
        }
    }
    // for(int i = 0; i <= h; i++)
    // {
    //     for(int j = 0; j <= w; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dp[h][w] << endl;
    return 0;
}