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

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vi prefix(n+1, 0), suffix(n+1, 0);
    rep(i, 1, n+1) {
        prefix[i] = gcd(prefix[i-1], a[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
        suffix[i] = gcd(suffix[i+1], a[i]);
    }
    int ans = 0;
    rep(i, 0, n) {
        int x = gcd(prefix[i], suffix[i+1]);
        ans = max(ans, x);
    }
    cout << ans << endl;
}