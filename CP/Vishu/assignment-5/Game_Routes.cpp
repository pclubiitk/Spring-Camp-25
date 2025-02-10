#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edge[n + 1], backedge[n + 1];
    vector<int> ind(n + 1, 0), dp(n + 1, 0);
    dp[1] = 1;

    f(i, 0, m) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        backedge[b].push_back(a);
        ind[b]++;
    }

    queue<int> q;
    f(i, 1, n + 1) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : edge[node]) {
            ind[next]--;
            if (ind[next] == 0) q.push(next);
        }
        for (int prev : backedge[node]) {
            dp[node] = (dp[node] + dp[prev]) % mod;
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}