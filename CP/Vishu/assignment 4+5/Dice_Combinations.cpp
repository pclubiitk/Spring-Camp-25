#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)
void solve()
{
    ll n;
    cin >> n;

    ll dp[n + 1] = {};

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n] << endl;

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