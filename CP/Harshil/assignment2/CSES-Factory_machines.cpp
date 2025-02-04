#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    long long int l=0,r=1e18;
    while(l<r)
    {
        long long int mid=(l+r)/2;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=mid/arr[i];
            if (sum >= t) break; 

        }
        if(sum>=t)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;
}