#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define s second
#define f first
#define vpll vector<pair<ll, ll>> 
#define all(v) v.begin(),v.end()
 
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n,0);
    for(auto &x:v) cin>>x;
    sort(all(v));
    ll res=0,res2=0;
    for(auto &x:v) res+=abs(x-v[(n-1)/2]),res2+=abs(x-v[n/2]);
    cout<<min(res,res2)<<endl;
}
