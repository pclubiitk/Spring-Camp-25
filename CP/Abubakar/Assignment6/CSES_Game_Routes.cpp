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

vector<vll> adj;
vll indegree, asn, dp;

void kahn(ll n) {
    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);//cout<<i<<"<--- \n";
        }
    }

    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        asn.pb(x);

        for (ll v : adj[x]) {
            if (indegree[v] == 1) q.push(v);
            indegree[v]--;
        }
    }
    
    if (asn.size() != n) {
        cout << "0"<<endl;
        return;
    }

    dp[n] = 1;
    for (ll i = n - 1; i >= 0; i--) {
        ll u = asn[i];
        for (auto v: adj[u]) {
            dp[u] = (dp[u] + dp[v]) % MOD;
        }
    }
    
    cout << dp[1] << endl;
}
//dp[i]how many ways to reach n

int main() {
    ll n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++;
    }

    kahn(n);
}






//Mistake:
    //even do originally some nodes have indgeree i we could still reach n
    // say indeg is 0 at 1,8 we reach 7 teleport to 9 then 10