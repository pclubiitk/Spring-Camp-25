#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define s second
#define f first
 
int main()
{
    FAST
    ll n;
    cin>>n;
    vector<ll>v(n,0),ps(n+1,0);
    map<ll,ll>mp;
    for(auto &x:v)cin>>x;
    ll res=0;
    ll ct=0;
    mp[0]=1;
    for(int i=0;i<n;i++)
    {
        res= (res+v[i]+n)%n;
        mp[(res+n)%n]++;
    }
    for(auto x:mp)
    {ct+=(((x.s)*(x.s-1))/2);}
    cout<<ct<<endl;
}
