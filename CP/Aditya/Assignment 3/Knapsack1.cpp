#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, w;
    cin >> n >> w;
    vi wt(n), val(n);
    rep(i, 0, n){
        cin >> wt[i] >> val[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
    rep(i, 1, n+1) {
        rep(j, 0, w+1) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
}