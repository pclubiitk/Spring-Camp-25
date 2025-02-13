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

vi adj[10001];
vector<bool> cats(10001, false);
int n, m;

int main() {
    cin >> n >> m;
    rep(i, 0, n) {
        cint(a);
        if (a) cats[a] = true;
    }
}