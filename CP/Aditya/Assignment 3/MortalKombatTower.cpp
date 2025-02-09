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

void solve() {
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(2, INF));
    dp[0][0] = 0;
    rep(i, 0, n) {
        rep(j, 0, 2) {
            int add = (j == 0) ? a[i] : 0;
            if (i+1 <= n) {
                dp[i+1][1-j] = min(dp[i+1][1-j], dp[i][j] + add);
            }
            if (i+2 <= n) {
                dp[i+2][1-j] = min(dp[i+2][1-j], dp[i][j] + add + (i + 1 < n ? a[i+1] : 0));
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(t);
    w(t) {
        solve();
    }
}