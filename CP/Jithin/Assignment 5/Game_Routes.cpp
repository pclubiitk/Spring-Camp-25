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

void dfs(int x, vvi& adj,vi& visited, vi& ans){
    if(visited[x]) return;
    visited[x]=1;
    for(int c: adj[x]){
        dfs(c,adj,visited,ans);
    }
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
    reverse(ans.begin(),ans.end());
    vll dp(n+1); // dp[i] gives no: of ways of reaching i;
    dp[1]=1;
    rep(i,0,n-1){
        int cur=ans[i];
        for(int el: adj[cur]){
            dp[el]+=dp[cur];
            dp[el]%=MOD;
        }
    }
    cout<<dp[n];
    return 0;
}