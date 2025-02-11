#include<bits/stdc++.h>
#include <sys/resource.h>

using namespace std;

int DFS(int node, int n, vector<vector<int>>& adj,vector<int>&dp)
{
    
    if(dp[node]!=-1)
    {
        return dp[node];
    }
    long long int paths=0;
    for(int i : adj[node] )
    {
        paths+=DFS(i,n,adj,dp);
        paths%=MOD;
    }
    dp[node]=paths;
    return paths;
}


int main()
{
    const rlim_t kStackSize = 64 * 1024 * 1024;   // 64 MB stack
    struct rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    if (rl.rlim_cur < kStackSize) {
        rl.rlim_cur = kStackSize;
        setrlimit(RLIMIT_STACK, &rl);
    }

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int>dp(n+1,-1);
    int ways=(DFS(1, n, adj,dp)%MOD);
    cout<<ways<<endl;
    
}