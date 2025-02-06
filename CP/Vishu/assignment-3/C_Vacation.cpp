#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)
void solve()
{
   int n;
   cin >> n;
   vector<int> dp(3);
   f(i,0,n){
    vector<int> arr(3);
    vector<int> dp2(3, 0);
    f(j,0,3){
            cin >> arr[j];
    }
    f(j,0,3){
        f(k,0,3){
            if (j != k){
                dp2[j] = max(dp2[j], dp[k] + arr[j]);
            }
        }
    }
    dp = dp2;
    }

    cout << max({dp[0], dp[1], dp[2]}) << endl;
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