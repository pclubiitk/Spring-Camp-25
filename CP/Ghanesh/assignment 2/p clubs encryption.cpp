#include<stdio.h>
#include<math.h>
int main(){
    int t;
    int x[104901];
    for(int i=0;i<=104900;i++){
        x[i]=1;
    }
    for(int i=2;i<=104900;i++){
        if(x[i]==1){
            for(int j=i*2;j<=104900;j+=i){
                x[j]=0;
            }
        }
    }
    long long int b[10000];
    int count=0;
    for(int i=2;i<=104900;i++){
        if(x[i]==1){
            b[count]=i;
            count++;
            if(count==10000){
                break;
            }
        }
    }
    scanf("%d\n",&t);
    while(t--){
    long long int n;
    int l;
    char s[27];
    for(int i=0;i<27;i++){
        scanf("%c",&s[i]);
        if(s[i]==' '){
            break;
        }
    }
    scanf("%lld %d\n",&n,&l);
    int u;
    for(int i=0;i<l;i++){
        u=0;
        while(n%b[i]==0){
            n=n/b[i];
            u++;
        }
        printf("%c",s[u]);
    }
    printf("\n");
    }
}