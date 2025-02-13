#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll,ll>>
#define vll vector<ll>
#define vdll vector<vector<ll>>

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define ss second
#define msi multiset<ll>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define MOD 1000000007
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);

ll binexp(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while(exp){
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
ll modinv(ll a, ll mod = MOD) {
    return binexp(a, mod - 2, mod);
}
 
int main(){
    FAST
    int t;
    cin >> t;
    
    vector<ll> q(t);
    ll h = 0;
    for (int i = 0; i < t; i++){
        cin >> q[i];
        if (q[i] > h)
            h = q[i];
    }
    

    vector<ll> v(h+1, 0), ps(h+1, 0), gp(h+1, 0);
    
 
    if(h >= 0) {
        v[0] = 1;
        ps[0] = 1;
        gp[0] = 1;  
    }
    if(h >= 1) {
        v[1] = 2;
        ps[1] = (ps[0] + v[1]) % MOD;  
        gp[1] = (4 * v[0] + v[1]) % MOD;
    }
    if(h >= 2) {
        v[2] = 8;
        ps[2] = (ps[1] + v[2]) % MOD; 

        gp[2] = (16 * v[0] + 4 * v[1] + v[2]) % MOD;
    }
    

    ll inv3 = modinv(3);
    

    for (ll n = 3; n <= h; n++) {
        ll num = (2 * ps[n-1] + gp[n-1]) % MOD;
        num = (num * inv3) % MOD; 
        ll add = binexp(2, 2LL * n - 2);
        v[n] = (num + add) % MOD;
        
        ps[n] = (ps[n-1] + v[n]) % MOD;
        gp[n] = (4 * gp[n-1] + v[n]) % MOD;
    }
    
    for(auto h : q){
        cout << v[h] % MOD << endl;
    }
    
    return 0;
}
