#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vdll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define inf (ll)1e12+5

const ll N = 1000010;

int main()
{
    ll n,t;
    cin>>t;
    n=6;
    vll v(n+1,0);
    iota(all(v),0);
    vll dp(t+1,0);
    dp[0]=1;
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-v[j]>=0) dp[i]=(dp[i]+dp[i-v[j]])%MOD;
        }
    }
//     for(int i=1;i<=t;i++)cout<<dp[i]<<" ";
// cout<<endl;
    cout<<dp[t]<<endl;
}