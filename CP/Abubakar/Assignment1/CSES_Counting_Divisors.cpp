#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
 
signed main()
{
    FAST
    ll n, x;
    cin >> n;
    vector<ll>v(1e6+1,0);
    ll vs= v.size();
    for (ll i = 1;i <vs;i++)
    {
        for (ll j = 0;j <vs;j += i)
        {
            v[j]++;
        }
    }
 
    for (ll i = 0;i < n;i++)
    {
        cin >> x;
        cout << v[x] << endl;
    }
}
