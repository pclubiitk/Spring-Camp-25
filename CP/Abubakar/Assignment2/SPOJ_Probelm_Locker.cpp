#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
const ll MOD = 1000000007;

ll binexp(ll b, ll e, ll m) {
    ll res = 1;
    while(e) {
        if(e & 1) res = (res * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << 2 << endl;
            continue;
        }
        if(n == 3){
            cout << 3 << endl;
            continue;
        }
        ll k = n / 3, r = n % 3, res = 0;
        if(r == 0)res = binexp(3, k, MOD);
        else if(r == 1)res = (binexp(3, k - 1, MOD) * 4LL) % MOD;
        else if(r==2)res = (binexp(3, k, MOD) * 2LL) % MOD;
        
        cout << res << endl;
    }
    
}
