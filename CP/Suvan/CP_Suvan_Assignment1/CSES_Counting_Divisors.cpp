#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int a;
        cin>>a;
        if(floor(sqrt(a)) == sqrt(a)){
            int flag = 1;
            for(int i = 1; i*i<a; i++){
                if(a%i == 0) flag += 2;
            }
            cout<<flag<<endl;
        }
        else{
            int flag = 0;
            for(int i = 1; i*i<=a; i++){
                if(a%i == 0) flag += 2;
            }
            cout<<flag<<endl;
        }
    }
    return 0;
}