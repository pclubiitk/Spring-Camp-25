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
#define MODINV 500000004
 
const int MAX_N = 200001;
vi adj[MAX_N]; 
vi ans(MAX_N, 0);
 
void dfs(int node) {
    for (auto child : adj[node]) {
        dfs(child);
        ans[node] += ans[child] + 1;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(n);
    vi bosses(n);
    rep(i, 0, n-1) {
        cin >> bosses[i];
        adj[bosses[i]].push_back(i+2);
    }
    dfs(1);
    rep(i, 1, n+1) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

