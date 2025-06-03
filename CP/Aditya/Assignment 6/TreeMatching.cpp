#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1e9
#define MOD 1000000007
const int MAX = 200001;
vi adj[MAX];
vector<bool> vis(MAX, false);
int dp[MAX][2];
void dfs(int node, int parent) {
    dp[node][0] = 0;
    dp[node][1] = 0;    
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            dp[node][0] += max(dp[child][0], dp[child][1]);
        }
    }    
    for (int child : adj[node]) {
        if (child != parent) {
            dp[node][1] = max(dp[node][1], dp[child][0] + 1 + dp[node][0] - max(dp[child][0], dp[child][1]));
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    cint(n);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;    
    return 0;
}
