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
 
ll sum (int k, vi a) {
    ll count = 0;
    rep(i, 0, a.size()) {
        count += k/a[i];
    }
    return count;
}
 
int main() {
    int n, t;
    cin >> n >> t;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll left = 1, right = right = *min_element(a.begin(), a.end()) * (ll)t;
    while(left < right) {
        ll mid = (left+right)/2;
        if (sum(mid, a) >= t) {
            right = mid;
        } else {
            left = mid + 1;   
        }
    }
    cout << left << endl;
}

//not completely correct