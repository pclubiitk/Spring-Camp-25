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
#define MOD 1000000007

int main() {
    fastio;    
    int n, k;
    cin >> n >> k;    
    vi c(n);
    rep(i, 0, n) {
        cin >> c[i];
    }    
    vector<vector<bool>> dp(k + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;    
    rep(i, 0, n) {
        for (int j = k; j >= c[i]; j--) {
            rep(l, 0, j+1) {
                if (dp[j - c[i]][l]) {
                    dp[j][l] = true;
                }
                if (l >= c[i] && dp[j - c[i]][l - c[i]]) {
                    dp[j][l] = true;
                }
            }
        }
    }
    
    vector<int> result;
    rep(i, 0, k+1) {
        if (dp[k][i]) {
            result.push_back(i);
        }
    }    
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}
