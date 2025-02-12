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
 
void solve() {
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    set<int> dp = {0};
    rep(i, 0, n) {
        set<int> x;
        for (int sum : dp) {
            x.insert(sum + a[i]);
        }
        dp.insert(x.begin(), x.end());
    }
    cout << dp.size() - 1 << endl;
    for (int sum : dp) {
        if (sum != 0) cout << sum << " ";
    }
}
int main() {
    solve();
}