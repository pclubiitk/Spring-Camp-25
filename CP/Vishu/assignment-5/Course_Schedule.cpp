#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

vector<int> dfs(int n, vector<vector<int> >& adj,vector<int>& enter)
{
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (enter[i] == 0)
            q.push(i);
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int x : adj[node]) {
            enter[x] -= 1;
            if (enter[x] == 0) {
                q.push(x);
            }
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> prereq(m+1);
    vector<vector<int>> adj(n + 1);
    vector<int> enter(n + 1, 0);
    
    for(int i = 0; i < m; ++i){
        cin >> prereq[i].first >> prereq[i].second;
        int x = prereq[i].first;
        int y = prereq[i].second;
        adj[x].push_back(y);
        enter[y] += 1;
    }
    vector<int> ans = dfs(n, adj, enter);
    if (ans.size() != n) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
