#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX
const ll MOD = 1000000007;

const ll N = 50007, K = 503;
vector<ll> adj[N];
ll dp[N][K];
ll n, k;
ll res = 0;

void dfs(ll v, ll p) {
    dp[v][0] = 1; // no. of ways in a subtree of i to reach from vertex i in jth lenhtg
    for (ll u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        for (ll l = 0; l < k; l++) {
            res += dp[u][l] * (dp[v][k - l-1]);
        }
        for (ll l = 1; l <= k; l++) {
            dp[v][l] += dp[u][l - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);
    cout << res << endl;
}
