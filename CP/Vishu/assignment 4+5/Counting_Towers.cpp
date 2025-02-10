#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

const int mod1 = pow(10,7);
ll dp[mod1+1];

void solve(){

    dp[1] = 2;
    dp[2] = 8;
    f(i,3,mod1 + 1)
        dp[i] = ((6 * dp[i-1] - 7 * dp[i-2]) % mod + mod) % mod;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();
    ll test = 1;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
