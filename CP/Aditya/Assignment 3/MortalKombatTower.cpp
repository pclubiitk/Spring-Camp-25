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
#define MOD 1e9 + 7

const int MAXN = 200005;
int dp[MAXN][2];
vi a;

int solve(int i, int player) {
    if (i >= sz(a)) return 0;
    if (dp[i][player] != -1) return dp[i][player];
    
    int res;
    if (player == 0) {
        res = min(solve(i + 1, 1), solve(i + 2, 1));
    } else {
        res = min(a[i] + solve(i + 1, 0), (i + 1 < sz(a) ? a[i] + a[i + 1] : a[i]) + solve(i + 2, 0));
    }
    
    return dp[i][player] = res;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        tr(x, a) cin >> x;
        
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
    return 0;
}
