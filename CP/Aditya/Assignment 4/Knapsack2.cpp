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

const int MAXV = 100001;
int main() {
    fastio;    
    int n, w;
    cin >> n >> w;    
    vi wt(n), v(n);
    rep(i, 0, n) {
        cin >> wt[i] >> v[i];
    }    
    vector<ll> dp(MAXV, 1e18);
    dp[0] = 0;    
    rep(i, 0, n) {
        for (int j = MAXV - 1; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + wt[i]);
        }
    }    
    ll ans = 0;
    for (int i = MAXV - 1; i >= 0; i--) {
        if (dp[i] <= w) {
            ans = i;
            break;
        }
    }    
    cout << ans << endl;
}
