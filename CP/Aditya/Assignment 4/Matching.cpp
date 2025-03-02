#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007

const int MAXN = 21;

int main() {
    fastio;    
    cint(n);    
    vector<vi> a(n, vi(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }    
    vector<ll> dp(1 << n, 0);
    dp[0] = 1;    
    rep(mask, 0, 1 << n) {
        int i = __builtin_popcount(mask);
        rep(j, 0, n) {
            if (!(mask & (1 << j)) && a[i][j]) {
                dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % MOD;
            }
        }
    }    
    cout << dp[(1 << n) - 1] << endl; 
}
