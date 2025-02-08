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
 
#define MOD 1000000007
 
ll ETF(ll n) {
    ll phi_n = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            phi_n -= phi_n / i;
        }
    }
    if (n > 1)
        phi_n -= phi_n / n;
    return phi_n;
}
 
ll modExp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    cint(n);
    w(n) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll expo = modExp(b, c, MOD - 1);        
        ll ans = modExp(a, expo, MOD);
        cout << ans << endl;
    }
}