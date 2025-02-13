#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
#define MOD 1000000007

vdll matrixmul(vdll m, vdll n)
{
    ll mrows = m.size();
    ll mcols = m[0].size();
    ll nrows = n.size();
    ll ncols = n[0].size();
    vdll res(mrows, vll(ncols, 0));
    for (ll i = 0; i < mrows; i++)
    {
        for (ll j = 0; j < ncols; j++)
        {
            for (ll k = 0; k < mcols; k++)
            {
                res[i][j] = (res[i][j] + m[i][k] * n[k][j] % MOD) % MOD;
            }
        }
    }
    return res;
}

vdll matrixexp(vdll m, ll pw)
{
    ll sz = m.size();
    vdll res(sz, vll(sz, 0));
    for (ll i = 0; i < sz; i++) res[i][i] = 1;
    while (pw)
    {
        if (pw & 1) res = matrixmul(res, m);
        m = matrixmul(m, m);
        pw >>= 1;
    }
    return res;
}

int main()
{
    ll n,k;
    cin >> n>>k;
    vdll adj(n,vll(n,0));
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)cin>>adj[i][j];
    }
    vdll rowo(1,vll(n,1));
    vdll colo(n,vll(1,1));
    
    vdll res = matrixexp(adj, k);
    vdll g = matrixmul(rowo,res);
    vdll t = matrixmul(g,colo);
    ll ans = t[0][0] % MOD;
    cout << ans << endl;
}
