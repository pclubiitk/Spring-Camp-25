#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int n, W;
    cin >> n >> W;

    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll > > dp(n+1,vector<ll> (W+1,0));
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=W; j++){
            if(w[i-1] <= j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][W];
    return 0;
}

