#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int x[n];
   int m=0;
   for(int i=0;i<n;i++){
       cin >> x[i];
       m+=x[i];
   }
   int dp[m+1];
   for(int i=0;i<=m;i++){
       dp[i]=-1;
   }
   dp[0]=0;
   for(int i=0;i<n;i++){
       for(int j=m-x[i];j>=0;j--){
           if(dp[j]!=-1){
               dp[j+x[i]]=1;
           }
       }
   }
   int count=0,a[m+1];
   for(int i=1;i<=m;i++){
       if(dp[i]!=-1){
           a[count]=i;
           count++;
       }
   }
   cout << count << "\n";
   for(int i=0;i<count;i++){
       cout << a[i] << " ";
   }
}
