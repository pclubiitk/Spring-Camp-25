#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1000000007

int main() {
    cint(n);
    vector<vi> a(n, vi(3));
    rep(i, 0, n) {
        rep(j, 0, 3) {
            cin >> a[i][j];
        }
    }
    rep(i, 1, n) {
        a[i][0] += max(a[i-1][1], a[i-1][2]);
        a[i][1] += max(a[i-1][0], a[i-1][2]);
        a[i][2] += max(a[i-1][0], a[i-1][1]);
    }
    cout << max(a[n-1][0], max(a[n-1][1], a[n-1][2]));
}