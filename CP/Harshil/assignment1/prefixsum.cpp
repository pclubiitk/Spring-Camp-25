#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q; 
    int a[n];
    long long int prefix[n];
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        prefix[i]=sum;
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l==1)
        {
            cout<<prefix[r-1]<<endl;
        }
        else
        {
            cout<<prefix[r-1]-prefix[l-2]<<endl;
        }
    }   
}