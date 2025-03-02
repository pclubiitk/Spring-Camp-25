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
#define MOD 1e9 + 7
 
bool is(const vector<ll>& m, ll t, ll ta) {
    ll num = 0;
    for (ll machine : m) {
        num += t / machine;
        if (num >= ta) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll n, t;
    cin >> n >> t;    
    vector<ll> m(n);
    rep(i, 0, n) cin >> m[i];
    
    ll left = 0, right = 1e18;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (is(m, mid, t)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}