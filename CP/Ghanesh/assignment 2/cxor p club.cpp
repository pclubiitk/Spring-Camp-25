#include<stdio.h>
#include<math.h>
int main(){
    int t;
    int tw[5];
        tw[0]=1;
        for(int i=0;i<4;i++){
            tw[i+1]=tw[i]*2;
        }
    char s[200001];
    scanf("%d\n",&t);
    while(t--){
        gets(s);
        int n=0;
        while(s[n]!='\0'){
            n++;
        }
        int a[n];
        for(int i=0;i<n;i++){
            if(s[i]=='P'){
                a[i]=0;
            }
            if(s[i]=='C'){
                a[i]=1;
            }
            if(s[i]=='l'){
                a[i]=2;
            }
            if(s[i]=='u'){
                a[i]=3;
            }
            if(s[i]=='b'){
                a[i]=4;
            }
        }
        int dp[n][32];
        for(int i=0;i<32;i++){
            dp[0][i]=0;
        }
                dp[0][tw[a[0]]]++;
        for(int i=1;i<n;i++){
           for(int j=0;j<32;j++){
              dp[i][j]=dp[i-1][j ^ tw[a[i]]];
              if(j==tw[a[i]]){
                dp[i][j]++;
              }
           }
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=dp[i][0];
        }
        printf("%lld\n",ans);
    }
}