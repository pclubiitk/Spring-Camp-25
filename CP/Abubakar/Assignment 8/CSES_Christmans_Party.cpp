#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vll>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define loop(i, n) for(ll i = 0; i < n; i++)
#define one(i, n) for(ll i = 1; i <= n; i++)
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define endl "\n"
#define MOD 1000000007
vll dp;
ll der(ll n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = ((der(n-1) + der(n-2)) * (n-1)) % MOD;
}

int main() {
    ll n;
    cin >> n;
    dp.assign(n+1,-1);
    cout << der(n) << endl;
}
