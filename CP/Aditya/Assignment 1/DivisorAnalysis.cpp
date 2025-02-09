#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
 
#define MOD 1000000007
ll modExp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    cint(n);
    ll nd = 1, sum = 1, num = 1;
    w(n) {
        ll sf = 0;
        int x, k;
        cin >> x >> k;
        nd *= k+1;
        rep(i, 0, k+1) {
            sf += pow(x, i);
        }
        sum *= sf;
        num *= pow(x, k);
    }   
    float c = (float)nd/2;
    ll akshat = modExp(num, c, MOD);
    cout << nd << " " << sum << " " << akshat;
}

//getting TLE