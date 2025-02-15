#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl "\n"
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
const int MAX = 500001;

vi adj[MAX];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(t);
    w(t) {
        cin >> n;
        vi a(n);
        tr(x, a) {
            cin >> x;
            x--;
        }
        fill(adj, adj+n, vi());
        rep(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans(n, '0');
        rep(i, 0, n) {
            map<int, int> m;
            for (int x : adj[i]) {
                m[a[x]]++;
            }
            m[a[i]]++;
            for (auto [val, count] : m) {
                if (count >= 2) ans[val] = '1';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
