#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1e9
#define MOD 1000000007
const int MAX = 200001;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vi> a(n, vi(31));
    rep(i, 0, n) {
        cin >> a[i][0];
        a[i][0]--;
    }
    rep(j, 1, 30) {
        rep(i, 0, n) {
            a[i][j] = a[a[i][j-1]][j-1];
        }
    }
    rep(i, 0, q) {
        int x, k;
        cin >> x >> k;
        int ans = --x;
        rep(j, 0, 30) {
            if ((1<<j)&k) {
                ans = a[ans][j];
            }
        }
        cout << ++ans << "\n";
    }    
}

//TLE