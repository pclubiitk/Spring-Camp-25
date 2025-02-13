#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007
#define sz size()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vll v(n);
    for (ll i = 0; i < n; i++){
        cin >> v[i];
    }
    vll ps;
    ps.reserve(n + 100005);
    ps.pb(0);

    for (ll i = n - 1; i >= 0; i--){
        ps.pb(ps.back() + v[i]);
    }
    
    ll q;
    cin >> q;
    while(q--){
        ll op;
        cin >> op;
        if(op == 1){
            ll l, r;
            cin >> l >> r;
            ll p=ps.sz-1;
            ll nl = p - l + 1;
            ll nr = p - r;
            cout << ps[nl] - ps[nr] << endl;
        }
        else if(op == 2){
            ll x;
            cin >> x;
            ps.push_back(ps.back() + x);
        }
    }
    
    return 0;
}
