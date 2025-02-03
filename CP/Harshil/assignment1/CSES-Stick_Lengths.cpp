#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(int arr[], int n)
{
    sort(arr,arr+n);
    int x=arr[n/2];
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=abs(arr[i]-x);
    }
    cout<<count<<endl;
    
}

int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(arr,n);
}