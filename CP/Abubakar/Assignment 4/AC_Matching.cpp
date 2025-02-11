#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vdll vector<vector<ll>>
using namespace std;
#define MOD 1000000007

ll n;
const ll N = 21;
vdll dp(1 << N, vll(N, -1));
vdll a;

ll rec(ll mask, ll i) {
    if (i == n) return 1;

    if (dp[mask][i] != -1) return dp[mask][i];

    ll ans = 0;
    for (int j = 0; j < n; j++) {
        if (a[i][j] && !(mask & (1 << j))) {
            ll new_mask = mask |(1 << j);
            ans = (ans + rec(new_mask, i + 1)) % MOD;
        }
    }

    return dp[mask][i] = ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    a = vdll(n, vll(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << rec(0, 0) << endl;
}
