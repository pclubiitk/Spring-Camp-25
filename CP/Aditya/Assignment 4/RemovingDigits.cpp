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
 
ll solve (int n) {
    vi dp(n+1, INF);
    dp[0] = 0;
    rep(i, 1, n+1) {
        int temp = i;
        while (temp) {
            int d = temp%10;
            dp[i] = min(dp[i], 1+dp[i-d]);
            temp/=10;
        }
    }
    return dp[n];
}
 
int main() {
   cint(x);
   cout << solve(x);
}