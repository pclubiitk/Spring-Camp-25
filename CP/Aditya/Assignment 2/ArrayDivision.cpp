#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
#define endl '\n';
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;

bool is(const vi& a, int k, ll maxsum) {
    int count = 1;
    ll sum = 0;
    tr(num, a) {
        if (num > maxsum) return false;
        if (sum + num > maxsum) {
            count++;
            sum = num;
        } else {
            sum += num;
        }
    }
    return (count <= k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    ll sum = 0, maxval = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        maxval = max(maxval, (ll)a[i]);
    }
    ll left = maxval, right = sum, ans = sum;
    while (left <= right) {
        ll mid = (left + right)/2;
        if (is(a, k, mid)) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << endl;
}