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
const int MAXN = 1000;

int main() {
    fastio;
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);    
    cint(n);
    string a, b;
    cin >> a >> b;    
    int f = 0;
    bool fl = false;    
    rep(i, 0, n) {
        if (a[i] != b[i]) {
            if (!fl) {
                f++;
                fl = true;
            }
        } else fl = false;
    }    
    cout << f << endl;
}
