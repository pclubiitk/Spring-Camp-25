#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

ll maxm(ll a , ll b){
    if(a > b) return a;
    return b;
}

void solve()
{
    ll n,w; 
    cin >> n >> w;
    vector<vector<ll>> dp(w+1, vector<ll>(n+1, 0));
    ll a[n], b[n];
    f(i,0,n){
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    f(i,1,w+1){
        f(j,1,n+1){
            dp[i][j] = maxm(dp[i][j], dp[i][j-1]);
            if (i - a[j-1] >= 0)
                dp[i][j] = maxm(dp[i][j], dp[i-a[j-1]][j-1] + b[j-1]);
            ans = maxm(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
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