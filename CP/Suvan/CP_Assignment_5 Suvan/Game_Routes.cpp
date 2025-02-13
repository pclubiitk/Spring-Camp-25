#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n;
vector<vector<int> > adj;
vector<long long> dp;

long long MOD = 1e9 + 7;
int dfs(int vertex) {
    // Take action on vertex after entering the vertex
    if(dp[vertex]!=-1) return dp[vertex];
    if(vertex == n) return dp[vertex] = 1;

    long long cnt = 0;

    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
        cnt = (cnt+dfs(child))%MOD;
        // Take action on child after exiting the child node
    }

    return dp[vertex] = cnt;
    // Take action on vertex after exiting the vertex
}


int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        int m;
        cin>>n>>m;
        adj.assign(n+1,vi());
        dp.assign(n+1, -1);

        for(int i = 0; i<m; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        cout<<dfs(1)<<endl;
    }

    return 0;
}
