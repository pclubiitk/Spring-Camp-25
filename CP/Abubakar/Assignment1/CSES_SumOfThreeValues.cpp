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
    ll n, x;
    cin >> n >> x;
    
    vpll v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i].f;
        v[i].s = i + 1;
    }
    
    
    sort(all(v));
    
   
    for(ll i = 0; i < n - 2; i++) {
        ll l = i + 1;
        ll r = n - 1;
        
        while(l < r) {
            ll res = v[i].f + v[l].f + v[r].f;
            
            if(res == x) {
                cout << v[i].s << " " << v[l].s << " " << v[r].s;
                return 0;
            }
            else if(res < x) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
