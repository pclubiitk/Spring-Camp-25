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
const ll MOD = (1LL << 32);
 

vdll matrixmul(vdll &m, vdll &n) {
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
 
vdll adj(64, vector<ll>(64, 0));

vdll add(const vdll &A, const vdll &B) {
    vdll C(64, vector<ll>(64, 0));
    for (ll i = 0; i < 64; i++)
        for (ll j = 0; j < 64; j++)
            C[i][j] = (A[i][j] + B[i][j]) % MOD;
    return C;
}

vdll I() {
    vdll I(64, vector<ll>(64, 0));
    for (ll i = 0; i < 64; i++) {
        I[i][i] = 1;
    }
    return I;
}
 

pair<vdll, vdll> powersum(vdll &A, ll n) {
    if(n == 1) {
        return { A, I() };
    }
    if(n % 2 == 0) {
        auto half = powersum(A, n / 2); 
        vdll P = matrixmul(half.ff, half.ff);
        vdll temp = matrixmul(half.ff, half.ss); 
        vdll res = add(half.ss, temp); 
        return { P, res };
    }
    else { 
        auto ep = powersum(A, n - 1); 
        vdll P = matrixmul(ep.ff, A);   
        vdll res = add(ep.ss, ep.ff); 
        return { P, res };
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll k;
    cin >> k;
 
    vector<pair<ll, ll>> pos = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
 


    for (ll r = 0; r < 8; r++) {
        for (ll c = 0; c < 8; c++) {
            ll ma = 8 * r + c;
            for (auto &x : pos) {
                ll dr = r + x.ff;
                ll dc = c + x.ss;
                if(dr >= 0 && dr < 8 && dc >= 0 && dc < 8) {
                    ll mi = 8 * dr + dc;
                    adj[ma][mi] = 1;
                }
            }
        }
    }
 

    vdll resm;
    {
        auto pr = powersum(adj, k + 1);
        resm = pr.ss; 
    }
    ll ans = 0;

    for (ll j = 0; j < 64; j++) {
        ans = (ans + resm[0][j]) % MOD;
    }
 
    cout << ans << endl;
    return 0;
}
// wrong answer on test 19