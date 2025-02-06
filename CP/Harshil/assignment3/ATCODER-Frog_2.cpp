#include<bits/stdc++.h>
using namespace std;
// #define INT_MAX 2147483647

int main()
{
    int n,k;
    cin>>n>>k;
    if(k>n)
    {
        k=n;
    }
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=0;
    for(int i=0;i<k-1;i++)
    {
        dp[i+1]=abs(arr[0]-arr[i+1]);
    }
    for(int i=0;i<n-k;i++)
    {
        int min=INT_MAX;
        for(int j=0;j<k;j++)
        {
            if(dp[i+j]+abs(arr[i+k]-arr[i+j])<min)
            {
                min=dp[i+j]+abs(arr[i+k]-arr[i+j]);
            }
        }
        dp[i+k]=min;
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<dp[i]<<" "; 
    // }
    cout<<dp[n-1]<<endl;
}