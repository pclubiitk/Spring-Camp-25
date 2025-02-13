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

void dfs(int x, vvi& adj,vi& visited){
    if(visited[x]) return;
    visited[x]=1;
    for(int c: adj[x]){
        dfs(c,adj,visited);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    vi visited(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    vi comp;
    rep(i,1,n){
        if(!visited[i]){
            dfs(i,adj,visited);
            comp.emplace_back(i);
        }
    }
    cout<<comp.size()-1<<"\n";
    rep(i,0,(int)comp.size()-2){ // comp.size() is unsigned.
        cout<<comp[i]<<" "<<comp[i+1]<<"\n";
    }
    return 0;
}