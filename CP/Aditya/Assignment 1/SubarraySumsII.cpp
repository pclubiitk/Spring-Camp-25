#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;    
    vector<ll> prefix(n + 1, 0);
    rep(i, 1, n+1) {
        cint(a);
        prefix[i] = prefix[i-1] + a;
    }    
    map<ll, int> sums;
    ll result = 0;    
    rep(i, 0, n+1) {
        result += sums[prefix[i] - x];
        sums[prefix[i]]++;
    }    
    cout << result << endl;
    return 0;
}
