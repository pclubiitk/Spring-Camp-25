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
#define inf LLONG_MAX/2

vdll matrixmul(vdll m, vdll n)
{
    ll sz = m.size();
    vdll res(sz, vll(sz, inf));
    for (ll i = 0; i < sz; i++)
    {
        for (ll j = 0; j < sz; j++)
        {
            for (ll k = 0; k < sz; k++)
            {
                res[i][j] = min(res[i][j], m[i][k] + n[k][j]);
            }
        }
    }
    return res;
}

vdll matrixexp(vdll m, ll pw)
{
    ll sz = m.size();
    vdll res(sz, vll(sz, inf));
    for (ll i = 0; i < sz; i++) res[i][i] = 0;
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
    ll n, m, k;
    cin >> n >> m >> k;
    
    vdll adj(n, vll(n, inf));
    
    for (ll i = 0; i < m; i++)
    {
        ll l, r, w;
        cin >> l >> r >> w;
        l--; r--;
        adj[l][r] = min(adj[l][r],w);
    }
    // for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(adj[i][j]==-1)adj[i][j]=inf;
    
    vdll res = matrixexp(adj, k);
    
    ll ans = res[0][n - 1];
    if(res[0][n-1]<inf){cout<<res[0][n-1];return 0;}
    cout<<-1<<endl;
    
}
