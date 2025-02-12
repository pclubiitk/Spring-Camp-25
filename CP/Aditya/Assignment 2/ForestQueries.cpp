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
vector<vi> solve(vector<vector<char>> &grid, int n) {
    vector<vi> prefix(n+1, vi(n+1, 0));
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            int value = (grid[i-1][j-1] == '*') ? 1 : 0;
            prefix[i][j] = value + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    } 
    return prefix;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<char>> a (n, vector<char>(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }
    vector<vi> prefix = solve(a, n);
    w(q) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix [x1-1][y1-1] << endl;
    }
}