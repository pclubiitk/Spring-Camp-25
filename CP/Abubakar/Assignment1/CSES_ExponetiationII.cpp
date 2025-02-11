
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7;
ll binexp(ll base, ll exp, ll m) {
   ll res = 1;
   while (exp > 0) {
       if (exp & 1)
           res = (res * base) % m;
       base = (base * base) % m;
       exp >>= 1;
   }
   return res;
}
 
ll invmod(ll a, ll mod) {
   return binexp(a, mod - 2, mod);
}
// a^p-1 mod p =1 so calc b^c mod p-1
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll df= binexp(b,c,MOD-1);
        ll fr = binexp(a,df,MOD);
        cout<<fr<<endl;
    }
}
