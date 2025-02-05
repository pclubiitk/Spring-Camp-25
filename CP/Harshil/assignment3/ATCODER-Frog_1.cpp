#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=0;i<n-2;i++)
    {
        dp[i+2]=min(dp[i]+abs(arr[i+2]-arr[i]),dp[i+1]+abs(arr[i+2]-arr[i+1]));
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<dp[i]<<" "; 
    // }
    cout<<dp[n-1]<<endl;
}