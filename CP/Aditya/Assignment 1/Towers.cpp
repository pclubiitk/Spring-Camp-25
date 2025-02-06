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
    //variation of largest increasing subsequence
    vector<int> lis;
 
    rep(i, 0, n) {
        auto it = upper_bound(all(lis), a[i]); 
        if (it != lis.end()) {
            *it = a[i];
        } else {
            lis.push_back(a[i]);
        }
    }
    cout << lis.size() << endl;
}