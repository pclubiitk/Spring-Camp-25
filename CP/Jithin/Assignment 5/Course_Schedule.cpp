#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

bool cycle;

void dfs(int x, vvi& adj,vi& visited, vi& ans){
    if(visited[x]==2) return;
    if(visited[x]==1){
        cycle=true;
        return;
    }
    visited[x]=1;
    for(int c: adj[x]){
        dfs(c,adj,visited,ans);
    }
    visited[x]=2;
    ans.emplace_back(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    vi visited(n+1);
    vi ans;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
    }
    rep(i,1,n){
        if(!visited[i]){
            dfs(i,adj,visited,ans);
        }
    }
    if(cycle){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    rep(i,0,n-1){
        cout<<ans[n-1-i]<<" ";
    }
    return 0;
}