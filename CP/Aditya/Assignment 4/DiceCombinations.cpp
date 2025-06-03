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
 
ll solve(int n) {
	ll dp[n+1] = {};
	dp[0] = 1;
	rep(i, 1, n+1) {
		for (int j = 1; j <= min(i, 6); j++) {
			dp[i] = (dp[i] + dp[i-j])%MOD;
		}
	}
	return dp[n];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cint(n);
	cout << solve(n);
}
