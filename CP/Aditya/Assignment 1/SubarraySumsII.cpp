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
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i]; 
    }
    sort(prefix.begin(), prefix.end()); 
    ll count = 0;
    for (int i = 0; i <= n; i++) {
        ll target = prefix[i] - x;
        auto lower = lower_bound(prefix.begin(), prefix.begin() + i, target);
        auto upper = upper_bound(prefix.begin(), prefix.begin() + i, target);
        count += (upper - lower); 
    }
    cout << count << "\n";
    return 0;
}
//messed up with negative numbers