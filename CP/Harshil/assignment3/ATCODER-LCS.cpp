#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            dp[i][j] = 0;
        }
    }
    vector<char>ans;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),1+dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1]){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    // cout<<dp[n][m]<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }

}