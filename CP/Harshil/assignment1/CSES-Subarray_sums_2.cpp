#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int prefix[n];  
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            prefix[i]=a[i];
        }
        else
        {
            prefix[i]=(prefix[i-1]+a[i]);
        }
    }
    int count=0;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[prefix[i]]++;
        if(m.find(prefix[i]-x)!=m.end())
        {
            count+=m[prefix[i]-x];
        }
    }
    count+=m[x];
    if(x==0)
    {
        count-=n;
    }
    cout<<count<<endl;
}