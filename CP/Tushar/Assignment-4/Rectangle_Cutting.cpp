#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>
void solve(){
    int a,b;
    cin>>a>>b;
    vector<vector<ll>> mat(a+1,vector<ll> (b+1,100000000000000));

    for(int i=1;i<=a;i++){
        // cout<<"ll\n";
        for(int j=1;j<=b;j++){
            // cout<<"lllll\n";
            if(j==i){mat[i][j]=0;continue;}
            for(int l=1;l<i;l++){
                mat[i][j]=min(mat[i][j],1+mat[i-l][j]+mat[l][j]);
            } 
            for(int l=1;l<j;l++){
                mat[i][j]=min(mat[i][j],1+mat[i][j-l]+mat[i][l]);
            } 
        }
    }
    // for(auto h:mat){
    //     for(auto j:h){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<mat[a][b];
}
int main(){
    int t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
