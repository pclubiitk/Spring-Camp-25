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
 
const int MAX_N = 1e6 + 5;
ll dp[MAX_N][2];
 
void precompute() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i, 1, MAX_N) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (2 * dp[i - 1][1] + dp[i - 1][0]) % MOD;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
    }
}