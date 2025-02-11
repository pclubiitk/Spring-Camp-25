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
    ll n;
    cin>>n;
    vll dp(n+1,inf);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        string s= to_string(i);

        for(auto x:s)
        {
            ll j= x-'0';
            dp[i]=min(dp[i],dp[i-j]+1);
        }
    }
    cout<<dp[n]<<endl;
}