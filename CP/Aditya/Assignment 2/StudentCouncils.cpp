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

int k, n;
vector<ll> a;
bool is(ll x) {
    ll total = 0;
    tr(students, a) {
        total += min(x, students);
    }
    return (total >= x*k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    cin >> k >> n;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];    
    ll low = 0, high = 1e18/k;
    while (low < high) {
        ll mid = low + (high - low + 1)/2;
        if (is(mid)) low = mid;
        else high = mid - 1;
    }
    cout << low << endl;    
}
