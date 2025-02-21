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
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<vi> dp(n+1, vi(m+1, 0));
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs = "";
    int i = n, j = m;
    while (i && j) {
        if (s[i-1] == t[j-1]) {
            lcs = s[i-1] + lcs;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << lcs << endl;
}