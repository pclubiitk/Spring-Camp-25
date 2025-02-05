#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int dp[n][3];
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}