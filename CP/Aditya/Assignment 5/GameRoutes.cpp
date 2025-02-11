#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
#define MOD 1000000007
 
vi adj[100001];
vi indeg(100001), dp(100001);
 
void solve(int n) {
    queue<int> q;
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }    
    while (!q.empty()) {
        int node = q.front();
        q.pop();        
        for (int child : adj[node]) {
            dp[child] = (dp[child] + dp[node]) % MOD;
            indeg[child]--;
            if (indeg[child] == 0) {
                q.push(child);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);    
    int n, m;
    cin >> n >> m;    
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;        
    }    
    solve(n);    
    cout << dp[n] << endl;    
    return 0;
}