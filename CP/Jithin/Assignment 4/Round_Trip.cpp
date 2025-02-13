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

vi cycle;

bool dfs(int c, int p, vvi& adj,vi& visited){
    cycle.emplace_back(c);
    visited[c]=1;
    for(int gc: adj[c]){
        if(gc==p) continue;
        if(visited[gc]){
            cycle.emplace_back(gc);
            int start = gc;
            int idx = find(cycle.begin(), cycle.end(), start) - cycle.begin();
            vector<int> actualCycle(cycle.begin() + idx, cycle.end());
            cycle=actualCycle;
            return true;
        }
        if(dfs(gc,c,adj,visited)){
            return true;
        }
    }
    cycle.pop_back();
    return false;
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
    rep(i,1,n){
        if(!visited[i]){
            if(dfs(i,i,adj,visited)){
                cout<<cycle.size()<<"\n";
                for(int el: cycle) cout<<el<<" ";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}