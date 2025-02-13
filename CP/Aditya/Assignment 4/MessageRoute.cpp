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
const int MAXN = 100001;
 
int n, m, daddy[MAXN], dist[MAXN];
bool vis[MAXN];
vi adj[MAXN];
queue<int> q;

int main() {
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int baby : adj[node]) {
            if (!vis[baby]) {
                dist[baby] = dist[node] + 1;
                vis[baby] = true;
                daddy[baby] = node;
                q.push(baby);
            }
        }
    }
    if (!vis[n]) cout << "IMPOSSIBLE" << endl;
    else {
        int x = n, d = dist[n];
        vi ans(d+1);
        for (int i = d; i >= 0; i--) {
            ans[i] = x;
            x = daddy[x];
        }
        cout << d+1 << endl;
        rep(i, 0, d+1) {
            cout << ans[i] << " ";
        }
    }
}