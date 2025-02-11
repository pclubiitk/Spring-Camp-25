#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
vector<vector<int> > adj;
vector<int> dis;
map<int,long long> cnt;
int m;
long long ans = 0;
void dfs(int vertex,int par = -1) {

    cnt[dis[vertex]]++;
    if(dis[vertex] >= m) ans += cnt[dis[vertex] - m];
    ans += cnt[dis[vertex] + m];
   
    // Take action on vertex after entering the vertex
    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
            if(child == par) continue;
            dis[child] = dis[vertex] + 1;
            dfs(child,vertex);
        // Take action on child after exiting the child node
    }
    cnt[dis[vertex]]--;
    // Take action on vertex after exiting the vertex
}
 
int main() {
    fast_io();
 
    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,m;
        cin>>n>>m;
        adj.resize(n);
        dis.resize(n);
        for(int i = 0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        dis.assign(n, 0);
        dfs(0);
        cout << ans / 2 << endl;
 
    }
 
    return 0;
}