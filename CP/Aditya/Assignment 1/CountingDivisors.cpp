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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    cint(n);
    w(n) {
        cint(x);
        int count = 0;
        for(int i = 1; i*i <= x; i++) {
            if (x%i == 0) {
                count+= 2;
                if (i*i == x) count --;
            }
        }
        cout << count << endl;
    }
}