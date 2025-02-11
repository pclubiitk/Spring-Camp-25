#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define loop(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
int main()
{
    ll n, t;
    cin >> n >> t;
    vll v(n);
    for (auto &x : v) cin >> x;
    
    ll l = 1, r = (*min_element(all(v)))*t, res = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll sum = 0;
        loop(i, n) {
 
            sum += (mid / v[i]);
        }
        
        if (sum >= t) 
        {
            res=mid;
            r = mid-1;; 
        }
        else {
 
          
                      l = mid+1;
        }
    }
    
    cout << res << endl;
}
