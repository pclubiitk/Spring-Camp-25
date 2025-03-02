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
const int MAXN = 10001;

set<int> adj[MAXN];
vector<bool> vis(MAXN, false);
int m, n;
vi dist(MAXN);

void bfs(int n) {
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int baccha : adj[node]) {
            if (!vis[baccha]) {
                dist[baccha] = dist[node] + 1;
                vis[baccha] = true;
                q.push(baccha);
            }
        }
    }    
    cout << dist[m] << endl;
}

int main() {
    cin >> n >> m;
    rep(i, 2, MAXN) {
        adj[i].insert(i-1);
    }
    rep(i, 1, 5001) {
        adj[i].insert(2*i);
    }    
    bfs(n);
}