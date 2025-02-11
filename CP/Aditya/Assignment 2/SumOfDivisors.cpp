#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
 
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
#define MOD 1000000007
 
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1, j; i <= n; i = j) {
        ll q = n/i;
        j = n/q + 1;
        ll sumj = ((((j%MOD)*((j-1)%MOD))%MOD)*mod_exp(2, MOD-2, MOD))%MOD;
        ll sumi = ((((i%MOD)*((i-1)%MOD))%MOD)*mod_exp(2, MOD-2, MOD))%MOD;
        ll range =  (sumj-sumi)%MOD;
        ans += ((q%MOD)*range)%MOD;
    }
    cout << ans << endl;
}
//khud se nahi chamka, had to take hints from USACO guide
//not passing all testcases