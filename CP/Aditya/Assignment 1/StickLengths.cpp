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
    cint(n);
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int median1 = a[n/2];
    int median2 = a[n/2 - 1];
    ll sum1 = 0, sum2 = 0;
    if (n % 2 == 0) {
        rep(i, 0, n) {
            sum1 += abs(median1 - a[i]);
            sum2 += abs(median2 - a[i]);
        }
        cout << min(sum1, sum2);
    }
    else {
        rep(i, 0, n) {
            sum1 += abs(median1 - a[i]);
        }
        cout << sum1 << endl;
    }
}