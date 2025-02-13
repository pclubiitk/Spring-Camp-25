#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)
void solve()
{
    string str, t; 
    cin >> str >> t;
    int n = str.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    f(i,1,n+1) {
        f(j,1,m+1) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (str[i-1] == t[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    string ans;
    int i = n, j = m,count = 0;
    while (i && j != 0) {
        if (str[i-1] == t[j-1]) {
            ans += str[i-1];
            i--, j--;
            count++;
        }
        else if (dp[i][j-1] >= dp[i-1][j]) {
            j--;
        }
        else i--;
    }
    for(int i = count - 1;i >= 0;i--){
        cout << ans[i];
    }
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