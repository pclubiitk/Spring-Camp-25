#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define ff first
#define pb push_back
#define ss second
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> adj(n+1);
    for (ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vector<ll> parent(n+1, -1);
    vector<ll> dist(n+1, -1);

    queue<ll> q;
    dist[1] = 0;
    parent[1] = 0; 
    q.push(1);
    
    while(!q.empty()){
        ll temp = q.front();
        q.pop();
        for (ll neighbour : adj[temp]){
            if (dist[neighbour] == -1){ 
                dist[neighbour] = dist[temp] + 1;
                parent[neighbour] = temp;
                q.push(neighbour);
            }
        }
    }
    

    if (dist[n] == -1){cout << "IMPOSSIBLE" << endl;return 0;}
    
    vector<ll> res;
    ll temp = n;
    ll th= dist[n]+1;
    cout << th<< endl;
    while (th--) {
        res.pb(temp);
        temp = parent[temp];
    }
    reverse(all(res));

    for (auto x : res)cout << x << " ";
    cout << endl;
    
    
}
