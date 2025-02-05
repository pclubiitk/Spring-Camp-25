#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long int mod(long long int a){
    if(a<0){
        return -a;
    }
    return a;
}
long long int min(long long int a,long long int b){
    if(a<b){
        return a;
    }
    return b;
}
int main(){
   int n,k;
   cin >> n >> k;
   int h[n];
   for(int i=0;i<n;i++)cin >> h[i];
   long long int dp[n];
   dp[0]=0;
   for(int i=1;i<n;i++){
       dp[i]=dp[i-1]+mod(h[i]-h[i-1]);
       for(int j=1;j<=k && i-j >=0 ;j++){
           dp[i]=min(dp[i],dp[i-j]+mod(h[i]-h[i-j]));
       }
   }
   cout << dp[n-1];
}
