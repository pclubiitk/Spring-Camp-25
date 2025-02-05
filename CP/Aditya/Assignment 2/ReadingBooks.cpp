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
 
int main() {
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll blackie = accumulate(a.begin(), a.begin() + n - 1, 0LL);
    ll brownie = accumulate(a.begin(), a.end(), 0LL);
    //cout << blackie << " " << brownie << endl;
    if (a[n-1] > blackie) {
        cout << 2*a[n-1];
    } else {
        cout << brownie;
    }
}