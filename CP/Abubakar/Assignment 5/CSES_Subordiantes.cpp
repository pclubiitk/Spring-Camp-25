#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
const ll MOD = 1000000007;
ll n;
vector<vll> adj;
vll sub;

void dfs(ll node) {
    for (ll child : adj[node]) {
        dfs(child);
        sub[node] += sub[child] + 1;
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    sub.resize(n + 1, 0);

    for (ll i = 2; i <= n; i++) {
        ll r;
        cin >> r;
        adj[r].pb(i); 
    }

    dfs(1);
    for (ll i = 1; i <= n; i++) cout << sub[i] << " ";
    cout << endl;
}
