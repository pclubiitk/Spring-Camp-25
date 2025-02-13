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

bool bfs(int x,vvi& adj, vi& visited,vi& steps, int n){
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        if(p==n) return true;
        for(int c: adj[p]){
            if(visited[c]) continue;
            steps[c]=p;
            visited[c]=1;
            q.push(c);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    vi visited(n+1);
    vi steps(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    if(bfs(1,adj,visited,steps,n)){
        vi ans;
        int cur=n;
        while(cur!=1){
            ans.emplace_back(cur);
            cur=steps[cur];
        }
        ans.emplace_back(1);
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()-1){
            cout<<ans[ans.size()-1-i]<<" ";
        }
    } else cout<<"IMPOSSIBLE";
    return 0;
}