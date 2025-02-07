#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vdll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define INF (ll)1e12+5

int main() {
    ll a, b;
    cin >> a >> b;
    
    vdll dp(a + 1, vll(b + 1, INF));

    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (ll k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (ll k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << endl;
}
