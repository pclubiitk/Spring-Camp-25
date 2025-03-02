#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int MAX = 1000001;

ll sum_of_divisors(ll n) {
    ll result = 0;
    for (ll i = 1, j; i <= n; i = j + 1) {
        j = n/(n/i);
        ll x = (n/i)%MOD;
        ll y = (j-i+1)%MOD;
        ll z = (i + j)%MOD;
        ll w = ((MOD + 1)/2)%MOD;
        result = (result + ((x*y)%MOD * z%MOD * w)%MOD)%MOD;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll n;
    cin >> n;
    cout << sum_of_divisors(n) << endl;    
    return 0;
}
