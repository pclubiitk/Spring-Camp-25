#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1e9 + 7
const int MAXN = 200000;
 
vi sieve() {
    vector<bool> isp(MAXN + 1, true);
    vi p; 
    isp[0] = isp[1] = false; 
    for (int i = 2; i*i <= MAXN; i++) {
        if (isp[i]) {
            for (int j = i*i; j <= MAXN; j += i) {
                isp[j] = false;
            }
        }
    } 
    rep(i, 2, MAXN+1) {
        if (isp[i]) p.push_back(i);
    } 
    return p;
} 
int main() {
    fastio; 
    cint(t);
    vi p = sieve();
    w(t) {    
        string s; ll n, l;
        cin >> s >> n >> l; 
        int size = sz(s);
        vector<int> ex(l);
        rep(i, 0, l) {
            int c = 0;
            while (!(n % p[i])) {
                c++;
                n /= p[i];
            }
            ex[i] = c;
        } 
        string ans;
        rep(i, 0, l) {
            ans += s[ex[i] % size];
        } 
        cout << ans << endl;
    }
}