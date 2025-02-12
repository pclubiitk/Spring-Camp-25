#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
const ll MOD = 1000000007;
const ll INF = 1e18;


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll b,n;
        cin>>b>>n;
        ll ct= b%n;
        bool alp=false;
        for(int k=1;k<=n;k++)
        {
            if(ct==1){cout<<"2 "<<k<<endl;alp=true;break;}
            if(ct==0){cout<<"1 "<<k<<endl;alp=true;break;}
            if(ct==n-1){cout<<"3 "<<k<<endl;alp=true;break;}
            ct= (ct*b)%n;
        }
        if(!alp)cout<<0<<endl;
    }

}