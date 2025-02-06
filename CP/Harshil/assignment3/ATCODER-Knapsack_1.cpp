#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(w+1, 0));
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if(j >= wt[i-1])
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            } 
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}