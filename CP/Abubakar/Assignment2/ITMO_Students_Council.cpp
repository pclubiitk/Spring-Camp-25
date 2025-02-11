#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define loop(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
int main()
{
    ll k;
    cin >> k;
    ll n;
    cin >> n;
    vll v(n, 0);
    for (auto& x : v) cin >> x;
    ll l = 0; ll r = 1e12;
    ll res = 0;


    ll mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        ll temp = mid;
        ll st = temp * k;
        for (auto x : v)
        {
            st -= min(temp, x);
        }
        if (st <= 0)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }

    }
    cout<<res<<endl;
}

