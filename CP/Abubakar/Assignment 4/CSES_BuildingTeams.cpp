#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back

const ll N = 1e5 + 2;
vll vis(N, 0), ct(N, -2);
vll adj[N];

ll f(ll x, ll y) {
    if (x == -1 || y == -1) return -1;
    if (x == 1 && y == 1) return -1;
    if (x == 0 && y == 0) return -1;
    if (x == 0 && y == 1) return 1;
    if (x == 1 && y == 0) return 0;
    if (x==0&&y == -2) return 1;
    if(x==1&&y==-2)return 0;
    

}


void dfs(ll node, ll parent) {
    vis[node] = 1;
    if (parent == -1) ct[node] = 0; 

    for (auto child : adj[node]) {
        ct[child] = f(ct[node], ct[child]);
        if (!vis[child])dfs(child, node); 
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    while (m--) {
        ll l, r;
        cin >> l >> r;
        adj[l].pb(r);
        adj[r].pb(l);
    }


    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i,-1);
    }

    
    // cout << "Node " << i << " -> " << ct[i] << endl;
    bool alp=false;
    for (ll i = 1; i <= n; i++)
    {
        if(ct[i]==-1||ct[i]==-2)
        {
            alp=true;
        }
    }
    if(alp) {cout<<"IMPOSSIBLE"<<endl;return 0;}
    for(ll i=1;i<=n;i++)
    {
        cout<<ct[i]+1<<" ";
    }

}
