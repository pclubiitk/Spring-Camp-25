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

string s;
ll nb, ns, nc, pb, ps, pc, r;
ll cb = 0, cs = 0, cc = 0;
bool is(ll x) {
    ll bc = max(0LL, x*cb - nb)*pb;
    ll sc = max(0LL, x*cs - ns)*ps;
    ll ccc = max(0LL, x*cc - nc)*pc;
    return (bc + sc + ccc <= r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    cin >> s;
    tr(c, s) {
        if (c == 'B') cb++;
        else if (c == 'S') cs++;
        else cc++;
    }    
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;    
    ll limit = max({nb + r/pb, ns + r/ps, nc + r/pc});    
    ll low = 0, high = limit;
    while (low < high) {
        ll mid = low + (high - low + 1)/2;
        if (is(mid)) low = mid;
        else high = mid - 1;
    }    
    cout << low << endl;    
}

