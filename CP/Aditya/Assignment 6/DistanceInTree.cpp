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
const int MAX = 50001;

vi adj[MAX];
int dp[MAX][501];
ll ans = 0;
int k, n;
void dfs(int v, int parent) {
    dp[v][0] = 1;    
    tr(u, adj[v]) {
        if (u == parent) continue;        
        dfs(u, v);        
        rep(i, 0, k) {
            ans += (ll)dp[v][i] * dp[u][k-i-1];
        }        
        rep(i, 0, k) {
            dp[v][i+1] += dp[u][i];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    cin >> n >> k;    
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    dfs(1, 0);    
    cout << ans << endl;    
    return 0;
}
