#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

bool is(const vi& s, int n, int c, int md) {
    int cows = 1;
    int last = s[0];    
    rep(i, 1, n) {
        if (s[i] - last >= md) {
            cows++;
            last = s[i];
            if (cows >= c) return true;
        }
    }
    return false;
}

int lmd(vi& s, int n, int c) {
    sort(all(s));    
    int low = 1, high = s[n-1] - s[0];
    int result = 0;    
    while (low <= high) {
        int mid = low + (high - low)/2;        
        if (is(s, n, c, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }    
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    cint(t);
    w(t) {
        int n, c;
        cin >> n >> c;
        vi stalls(n);
        rep(i, 0, n) cin >> stalls[i];        
        cout << lmd(stalls, n, c) << endl;
    }  
}
