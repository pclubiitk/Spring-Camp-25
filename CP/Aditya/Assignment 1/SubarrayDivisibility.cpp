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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cint(n);
    vector<ll> prefix(n+1, 0);
    unordered_map<ll, ll> count;
    count[0] = 1;
    ll ans = 0;
    rep(i, 1, n+1) {
        cint(x);
        prefix[i] = (prefix[i-1] + x)%n;
        if (prefix[i] < 0) prefix[i] += n;
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    cout << ans << endl;
}