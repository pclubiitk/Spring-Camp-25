#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define f first
#define s second
#define all(v) v.begin(),v.end()
ll rec(ll x,ll y)
{
   if(x>=y)return x-y;
   if(y%2==0)return 1+rec(x,y/2);
   return 2+rec(x,(y+1)/2);
   
}
int main()
{
    ll m,n;
    cin>>m>>n;
    ll ans= rec(m,n);
    cout<<ans<<endl;
}