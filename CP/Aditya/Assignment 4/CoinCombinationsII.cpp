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
#define INF 1e9
#define MOD 1000000007
 
ll solve (int n, int x, vi &coins) {
    ll dp[x+1] = {};
    dp[0] = 1;
    for (int j : coins) {
        rep(i, 1, x+1) {
            if (j > i) continue;
            dp[i] = (dp[i] + dp[i - j])%MOD;
        }
    }
    return dp[x];
}
 
int main() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    cout << solve(n, x, a) << endl;
}