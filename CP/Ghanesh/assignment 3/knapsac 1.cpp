#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long int max(long long int a,long long int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
   int n,W;
   cin >> n >> W;
   int w[n];
   long long int v[n];
   for(int i=0;i<n;i++)cin >> w[i] >> v[i];
   
   long long int dp[W+1];
   
   for(int i=0;i<=W;i++){
       dp[i]=0;
   }
   for(int j=0;j<n;j++){
   for(int i=W-w[j];i>=0;i--){
       dp[i+w[j]]=max(dp[i+w[j]],dp[i]+v[j]);
   }
   }
   long long int mi=0;
   for(int i=0;i<=W;i++){
       mi=max(mi,dp[i]);
       
   }
   cout << mi;
}
