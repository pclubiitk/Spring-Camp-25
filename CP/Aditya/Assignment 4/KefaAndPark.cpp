#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007

const int MAXN = 1e5 + 1;
vi adj[MAXN];
int cats[MAXN], n, m, ans = 0;
void dfs(int v, int p, int cc) {
    if (cats[v]) cc++;
    else cc = 0;
    if (cc > m) return;    
    bool is = true;
    for (int u : adj[v]) {
        if (u != p) {
            is = false;
            dfs(u, v, cc);
        }
    }    
    if (is) ans++;
}

int main() {
    fastio;    
    cin >> n >> m;    
    rep(i, 1, n+1) {
        cin >> cats[i];
    }    
    rep(i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    dfs(1, 0, 0);    
    cout << ans << endl;    
}
