#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long int mod(long long int a){
    if(a<0){
        return -a;
    }
    return a;
}
long long int max(long long int a,long long int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
   int n;
   cin >> n;
   long long int a[n][3];
   for(int i=0;i<n;i++)cin >> a[i][0] >> a[i][1] >> a[i][2];
   long long int dp[n][3];
   for(int i=0;i<n;i++){
       for(int j=0;j<3;j++){
           dp[i][j]=0;
       }
   }
   for(int i=0;i<3;i++){
       dp[0][i]=a[0][i];
   }
   for(int i=1;i<n;i++){
       for(int j=0;j<3;j++){
           dp[i][j]=max(dp[i-1][(j+1)%3] +a[i][j],dp[i-1][(j+2)%3]+a[i][j]);
           }
   }
   long long int x=0;
   for(int i=0;i<3;i++){
       x=max(x,dp[n-1][i]);
   }
   cout << x ;
}
