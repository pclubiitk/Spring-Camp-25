#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define cint(n) int n; cin >> n;
typedef vector<int> vi;
 
int main() {
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
 
    // longest increasing subsequence ka variation
    vector<int> lis;
 
    rep(i, 0, n) {
        auto it = upper_bound(lis.begin(), lis.end(), a[i]);
 
        if (it != lis.end()) {
            *it = a[i];
        } else {
            lis.push_back(a[i]);
        }
    }
    cout << lis.size() << endl;
}