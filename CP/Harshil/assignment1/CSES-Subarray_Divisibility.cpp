#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a[i]=((temp%n)+n)%n;
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
            prefix[i]=(prefix[i-1]+a[i])%n;
        }
    }
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[prefix[i]]++;
    }
    long long int count=0;
    for(auto i:m)
    {
        if(i.first==0)
        {
            count+=i.second;
        }
        count+=((long long int)(i.second)*(i.second-1))/2;
    }
    cout<<count<<endl;
}