#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count=0;
    long long int current_sum=0;
    int i=-1,j=-1;
    while(j<n)
    {
        if(current_sum==x)
        {
            count++;
            j++;
            current_sum+=a[j];
        }
        else if(current_sum<x)
        {
            j++;
            current_sum+=a[j];
        }
        else
        {
            i++;
            current_sum-=a[i];
        }
        // cout<<i<<" "<<j<<endl;
    }
    cout<<count<<endl;
}