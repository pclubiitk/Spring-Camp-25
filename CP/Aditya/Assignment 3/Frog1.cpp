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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vi dp(n, INT_MAX);
    dp[0] = 0;
    rep(i, 0, n) {
        for (int j = i+1; j <= i+2; j++) {
            if (j < n) {
                dp[j] = min(dp[j], dp[i] + abs(a[i]-a[j]));
            }
        }
    }
    cout << dp[n-1];

}
