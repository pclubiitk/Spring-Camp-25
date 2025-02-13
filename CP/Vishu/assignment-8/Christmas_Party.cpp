#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n+1);
    arr[1] = 0;
    arr[2] = 1;
    f(i,3,n+1){
        arr[i] = ((i-1) * (arr[i-1] + arr[i-2])) % mod;
    }
    cout << arr[n] << endl;
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