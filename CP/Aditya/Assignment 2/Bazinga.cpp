#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1e9 + 7

const int LIMIT = 100000; 
const int MAX_K = 2000000; 
vi gen() {
    vector<bool> isprime(LIMIT+1, true);
    vi p;
    isprime[0] = isprime[1] = false;
    rep(i, 2, LIMIT+1) {
        if (isprime[i]) {
            p.push_back(i);
            for (int j = i * 2; j <= LIMIT; j += i) {
                isprime[j] = false;
            }
        }
    }
    vi ans;
    int n = sz(p);
    rep(i, 0, n) {
        rep(j, i+1, n) {
            ll product = (ll)p[i] * p[j];
            if (product > 1e9) break; 
            ans.push_back(product);
        }
    }
    sort(all(ans));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi ans = gen();
    cint(t);
    w(t) {
        int k;
        cin >> k;
        cout << ans[k-1] << endl;
    }
}

//TLE

