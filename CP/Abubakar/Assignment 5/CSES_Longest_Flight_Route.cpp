#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define inf 1e12

vector<vll> adj;
vll indegree, asn, dp;
vll dist;
vll parent;
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
        cout << "IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        ll j=asn[i];
        for(auto v: adj[j])
        {
            ll temp=dist[v];
            dist[v]=max(dist[v],dist[j]+1);
            if(dist[v]!=temp)parent[v]=j;
        }
    }


}
//dp[i]how many ways to reach n

int main() {
    ll n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    dist.resize(n+1,-inf);
    parent.resize(n+1,-1);
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++;
    }
    dist[1]=0;
    kahn(n);
    ll temp=n;
    vll ans;
    if(dist[n]<0){cout<<"IMPOSSIBLE"<<endl;return 0;}
    while(temp!=-1)
    {
        ans.pb(temp);
        temp = parent[temp];
    }
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    

}




