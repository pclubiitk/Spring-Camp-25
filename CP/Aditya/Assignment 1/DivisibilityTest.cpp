#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
#define endl '\n';
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define MOD 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cint(t);
    w(t) {
        int b,n;
        cin >> b >> n;
        ll rem = b%n;
        bool found = false;
        rep(i, 1, n+1) {
            if(rem == 1) {
                cout<<"2 "<< i <<endl;
                found = true;
                break;
            }
            if(rem == 0) {
                cout << "1 " << i <<endl;
                found = true;
                break;
            }
            if(rem == n-1) {
                cout << "3 " << i << endl;
                found = true;
                break;
            }
            rem = (rem*b)%n;
        }
        if(!found) cout << 0 << endl;
    }
 
}