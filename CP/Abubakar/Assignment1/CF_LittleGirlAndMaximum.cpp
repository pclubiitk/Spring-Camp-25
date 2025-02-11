#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define s second
#define f first
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(),v.end()

int main() {
    FAST
    ll n, q;
    cin >> n >> q;

    vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    

    vector<ll> s(n + 1, 0); //shru 
    vector<ll> k(n + 1, 0);//khtm
    

    while(q--) {
        ll l, r;
        cin >> l >> r;
        s[l]++;             
        k[r]++;              
    }
    

    for(int i = 1; i <= n; i++) {
        s[i] = s[i] + s[i-1];
    }
    

    for(int i = 1; i <= n; i++) {
        k[i] = k[i] + k[i-1];
    }
    

    vector<ll> res(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        res[i] = s[i] - k[i-1];
    }
    

    sort(res.begin() + 1, res.end());
    sort(v.begin() + 1, v.end());
    
  
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll ct=v[i] * res[i];
        ans += ct;
    }
    
    cout << ans << endl;
    return 0;
}
