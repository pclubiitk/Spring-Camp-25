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
#define inf LLONG_MAX
const ll MOD = 1000000007;
 
vdll matrixmul(vdll &m,vdll &n) {
    ll mrows = m.size();
    ll mcols = m[0].size();
    ll ncols = n[0].size();
    vdll res(mrows, vll(ncols, 0));
    for (ll i = 0; i < mrows; i++) {
        for (ll j = 0; j < ncols; j++) {
            for (ll k = 0; k < mcols; k++) {
                res[i][j] = (res[i][j] + (m[i][k] % MOD) * (n[k][j] % MOD)) % MOD;
            }
        }
    }
    return res;
}
 
vdll matrixexp(vdll m, ll pw) {
    ll sz = m.size();
    vdll res(sz, vll(sz, 0));
    for (ll i = 0; i < sz; i++)
        res[i][i] = 1;
    while (pw) {
        if (pw & 1)
            res = matrixmul(res, m);
        m = matrixmul(m, m);
        pw >>= 1;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, k;
    cin >> n >> k;
    vdll b(n+3, vll(1, 0));
    vll init(n, 0);
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        b[n-1-i][0] = x;
        init[i] = x;
    }
    

    b[n][0]   = n*n;
    b[n+1][0] =n;                     
    b[n+2][0] = 1;                           

    vdll g(n+3, vll(n+3, 0));
    

    for (int i = 0; i < n; i++){
        cin >> g[0][i]; 
        g[0][i] %= MOD;
    }
    
    ll p, q, r;
    cin >> p >> q >> r;

    g[0][n]   = r;
    g[0][n+1] = q;
    g[0][n+2] = p;
    
    for (int i = 1; i < n; i++){
        g[i][i-1] = 1;
    }
    

    g[n][n]   = 1;  g[n][n+1] = 2;  g[n][n+2] = 1;
    g[n+1][n+1] = 1;  g[n+1][n+2] = 1;
    g[n+2][n+2] = 1;
    
    if (k < n) {
        cout << init[k] << endl;
        return 0;
    }
    

    ll st = k - (n - 1);
    vdll j = matrixexp(g, st);
    vdll res = matrixmul(j, b);
    
    ll ans = res[0][0] % MOD;
    cout << ans << endl;
    
    return 0;
}
