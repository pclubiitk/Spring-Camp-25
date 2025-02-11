#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;

#define MOD 1000000007

ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    cint(t);
    w(t) {
        ll n;
        cin >> n;
        if (n <= 3) cout << n << endl;
        else {
            ll result;
            if (n % 3 == 0) {
                result = mod_exp(3, n / 3, MOD);
            } else if (n % 3 == 1) {
                result = (4 * mod_exp(3, (n - 4) / 3, MOD)) % MOD;
            } else {  
                result = (2 * mod_exp(3, (n - 2) / 3, MOD)) % MOD;
            }
            cout << result << endl;
        }        
    }
}
