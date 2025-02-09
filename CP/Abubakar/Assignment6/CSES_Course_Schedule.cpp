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
vll indegree, asn;

void kahn(ll n, ll m) {
    queue<ll> q;
    for (ll i = n; i>0; i--) {
        if (indegree[i] == 0) q.push(i);
    }
    //even though loop runs forward backward doesnt matter 
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        asn.pb(x);
        
        for (ll nodes : adj[x]) {

            if (indegree[nodes] == 1) q.push(nodes);
            indegree[nodes]--;
        }
    }
    if(asn.size()!=n){cout<<"IMPOSSIBLE"<<endl; return;}
    for (auto x : asn) cout << x << " ";
    cout << endl;
}

int main() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    
    while (m--) {
        ll l, r;
        cin >> l >> r;
        adj[l].pb(r);
        indegree[r]++;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     reverse(all(adj[i]));
    // }
    
    kahn(n,m);
}

