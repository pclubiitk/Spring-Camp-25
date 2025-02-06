#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long>& v,long long time,long long int p)
{
    long long sum=0;
    for(auto& i:v)
    {
        if(time/i==0) break;
        sum+=(time/i);
    }
    return sum>=p;

}
int main()
{
    long long int n,p;cin>>n>>p;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    long long int lo=1,hi=p*1LL*v[0],mid;
    while(lo<hi)
    {
        mid=lo+(hi-lo)/2;
        if(check(v,mid,p)) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
}