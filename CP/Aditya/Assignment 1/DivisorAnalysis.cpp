#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007

ll modExp(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll m) {
    return modExp(a, m - 2, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cint(n);    
    ll nd = 1, sum = 1, prod = 1;
    ll div_cnt2 = 1;    
    w(n) {
        ll x, k;
        cin >> x >> k;        
        nd = (nd * (k+1))%MOD;        
        ll term = (modExp(x, k + 1, MOD) - 1 + MOD)%MOD;
        term = (term * modInverse(x-1, MOD))%MOD;
        sum = (sum * term)%MOD;        
        prod = modExp(prod, k+1, MOD) * modExp(modExp(x, (k*(k+1)/2), MOD), div_cnt2, MOD)%MOD;
        div_cnt2 = div_cnt2 * (k+1) % (MOD-1);
    }
    cout << nd << " " << sum << " " << prod << endl;    
    return 0;
}
