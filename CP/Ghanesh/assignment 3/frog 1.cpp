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
   int n;
   cin >> n;
   int h[n];
   for(int i=0;i<n;i++)cin >> h[i];
   long long int dp[n];
   dp[0]=0;
   dp[1]=mod(h[1]-h[0]);
   for(int i=2;i<n;i++){
       dp[i]=min(dp[i-1]+mod(h[i]-h[i-1]),dp[i-2] + mod(h[i]-h[i-2]));
   }
   cout << dp[n-1];
}
