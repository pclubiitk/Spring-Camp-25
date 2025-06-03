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
#define MOD 1000000007

const int MAXN = 301;
vector<vector<vector<double>>> dp(MAXN, vector<vector<double>>(MAXN, vector<double>(MAXN, -1.0)));
double solve(int one, int two, int three, int n) {
    if (one + two + three == 0) return 0;
    if (dp[one][two][three] >= 0) return dp[one][two][three];    
    double res = n;
    if (one) res += one * solve(one-1, two, three, n);
    if (two) res += two * solve(one+1, two-1, three, n);
    if (three) res += three * solve(one, two+1, three-1, n);
    res /= (one + two + three);    
    return dp[one][two][three] = res;
}

int main() {
    fastio;    
    cint(n);    
    vi c(4, 0);
    rep(i, 0, n) {
        cint(x);
        c[x]++;
    }    
    cout << fixed << setprecision(10) << solve(c[1], c[2], c[3], n) << endl;
}
