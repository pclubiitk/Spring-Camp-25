#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define inf (ll)1e12+5
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>

const ll N = 1e2 + 5;
ll n, W;
ll v[N], w[N], dp[N][100001];

ll solve(ll ind, ll V) {
    if (V < 0)
        return inf;
    ll &ans = dp[ind][V];
    if (ans != -1)
        return ans;
    if (ind == n)
        return ans = (V == 0 ? 0 : inf);
    return ans = min(w[ind] + solve(ind + 1, V - v[ind]), solve(ind + 1, V));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> W;
    for (ll i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    for (ll i = 100000; i >= 0; i--){
        if (solve(0, i) <= W){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
