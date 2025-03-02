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
const int MAX = 1000001;
int fc[MAX];
int px[11][MAX];
void sieve() {
    rep(i, 2, MAX) {
        if (fc[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                fc[j]++;
            }
        }
    }
}
void pc() {
    rep(i, 1, MAX) {
        rep(j, 0, 11) {
            px[j][i] = px[j][i-1];
            if (fc[i] == j) {
                px[j][i]++;
            }
        }
    }
}
int main() {
    fastio;   
    sieve(); pc();    
    cint(t);
    w(t) {
        int a, b, n;
        cin >> a >> b >> n;
        cout << px[n][b] - px[n][a-1] << endl;
    }   
}
