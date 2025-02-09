#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(ll a, ll b)
{
    return a + b - (a & b);
}

int haha(ll i, vector < ll > v)
{
    ll s = v.size();
    ll res = 0;
    for (int j = i; j < s; j++)
    {
        res = f(v[j - 1], v[j]);
        v[j] = res;
    }
    return res;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ct = 0;
        vector < ll > v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll res= v[n-1];
        for(int i=n-2; i>=0; i--)
        {
            ll y= f(res,v[i]);
            ct+= y;
            res=y;
        }
        ll alp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            alp = alp + v[i];
        }
        cout << ct - alp << endl;

    }
}
