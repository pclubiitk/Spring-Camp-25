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

int main() {
    fastio;
    ll sum = 0, mc = 0, s = 0;
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > mc) {
            s = mc;
            mc = a[i];
        } else if (a[i] > s) s = a[i];
    }
    if(n == 1) {
        cout << 3 * a[0] << endl;
    } else if (n == 2) { 
        cout<< 3 * max(a[0], a[1]) << endl;
    } else {
        cout << min(mc * 2 + max(sum - mc - s, mc), max(sum - mc - s, s) + 2 * mc) << endl;
    }    
}