#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1e9 + 7

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vi prefix(n+1, 0);
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        prefix[l-1]++;
        prefix[r]--;
    }
    rep(i, 1, n) {
        prefix[i] += prefix[i-1];
    }
    sort(all(a), greater<int>());
    sort(all(prefix), greater<int>());
    ll ans = 0;
    rep(i, 0, n) {
        ans += (ll)a[i]*prefix[i];
    }
    cout << ans << endl;
}