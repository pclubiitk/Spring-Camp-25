#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
    vector<vector<int>> dp(n,vector<int>(m));
    bool flag=true;
    for(int j=0;j<m;j++){
        if(v[0][j]=='#') 
        {
            dp[0][j]=0;
            flag=false;
        }
        if(flag) dp[0][j]=1;
        else dp[0][j]=0;
    }
    flag=true;
    for(int i=0;i<n;i++)
    {
        if(v[i][0]=='#') 
        {
            dp[i][0]=0;
            flag=false;
        }
        if(flag) dp[i][0]=1;
        else dp[i][0]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(v[i][j]=='#') dp[i][j]=0;
            else{
            dp[i][j]=(dp[i-1][j]%M+dp[i][j-1]%M)%M;
            }
        }
    }
    cout<<dp[n-1][m-1];
}