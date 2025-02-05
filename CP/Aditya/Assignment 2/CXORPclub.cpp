#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
#define clong(n) long long n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
ll cxorp(const string& s) {
    unordered_map<ll, ll> flags;
    flags[0] = 1; 
    ll x = 0;
    ll count = 0;    
    for (char c : s) {
        x ^= c; 
        count += flags[x];
        flags[x]++;
    }    
    return count;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    cint(t);    
    w(t) {
        string s;
        cin >> s;
        cout << cxorp(s) << endl;
    }
}