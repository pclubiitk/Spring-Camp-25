#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long int mod=1000000000;
long long int n,k;
long double small=0.000001;
long long int min(long long int a,long long int b){
    if(a<b){
        return a;
    }
    return b;
}
long long int fun(long long int  x,long long int a[]){
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=min(a[i],x);
    }
    return sum;
}
long long int find(long long int l,long long int r,long long int a[]){
    if(r-l==1){
        return l;
    }
    long long int m=(l+r)/2;
    long long int temp=fun(m,a);
    if(temp >=k*m){
        return find(m,r,a);
    }
    else{
        return find(l,m,a);
    }
}
int main(){
    cin >> k >>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    cout << find(1,10000000000000000,a);
}
