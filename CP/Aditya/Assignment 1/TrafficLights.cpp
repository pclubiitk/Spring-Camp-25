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
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, n;
    cin >> x >> n;
 
    set<int> lights{0, x};
    multiset<int> diff{x};
    rep(i, 0, n) {
        cint(l);
        auto it1 = lights.upper_bound(l);
        auto it2 = it1;
        --it2;
 
        diff.erase(diff.find(*it1 - *it2));
        diff.insert(l - *it2);
        diff.insert(*it1 - l);
        lights.insert(l);
 
        auto ans = diff.end();
        --ans;
        cout << *ans << endl;
    }
}