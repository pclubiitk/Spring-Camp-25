#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    FAST
    ll n;
    cin >> n;
    
    vector<ll> v(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }
    
  
    vector<ll> pg(n + 1);//pg 4 pref gcd
    pg[0] = 0; 
    for(int i = 0; i < n; i++) {
        pg[i + 1] = gcd(pg[i], v[i]);
    }
    
 
    vector<ll> sg(n + 2);//sg 4 suf gcd
    sg[n + 1] = 0; 
    for(int i = n-1; i >= 0; i--) {
        sg[i + 1] = gcd(sg[i + 2], v[i]);
    }
    

    ll maxc = 0;
    for(int i = 0; i < n; i++) {
    
        ll ct = gcd(pg[i], sg[i + 2]);
        maxc = max(maxc, ct);
    }
    
    cout << maxc << endl;
    return 0;
}
