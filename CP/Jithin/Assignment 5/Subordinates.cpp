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

void dfs(int x, vvi& adj,vi& dp){
    dp[x]=1;
    for(int c: adj[x]){
        dfs(c,adj,dp);
        dp[x]+=dp[c];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vvi adj(n+1);
    vi dp(n+1);
    rep(i,2,n){
        int x;
        cin>>x;
        adj[x].emplace_back(i);
    }
    dfs(1,adj,dp);
    rep(i,1,n){
        cout<<dp[i]-1<<" ";
    }
    return 0;
}