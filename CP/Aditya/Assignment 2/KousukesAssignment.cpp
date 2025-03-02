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
#define MOD 1e9 + 7

void solve() {
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }    
    ll sm = 0, ans = 0;
    set<ll> s;
    s.insert(0);    
    rep(i, 0, n) {
        sm += a[i];
        if (s.find(sm) == s.end()) {
            s.insert(sm);
        } else {
            s.clear();
            s.insert(sm);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    fastio;
    cint(t);
    w(t) {
        solve();
    }
}

