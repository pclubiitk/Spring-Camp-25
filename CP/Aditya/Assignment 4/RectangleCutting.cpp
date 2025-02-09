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
 
void solve(int a, int b) {
    vector<vi> dp(a+1, vi(b+1, INF));
    rep(i, 1, a+1) {
        rep(j, 1, b+1) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                rep(k, 1, j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
                rep(k, 1, i) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}
int main() {
    int a, b;
    cin >> a >> b;
    solve(a, b);
}