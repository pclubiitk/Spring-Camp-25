#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main() {
    fast_io();
 
    int test = 1;
    //cin >> test;
    while(test--) {
        int len;
        cin>>len;
        vi num(len);
        for(int i = 0; i<len; i++){
            cin>>num[i];  
        }
        sort(all(num));
        if(len%2){
            int tar = num[(len-1)/2];
            long long diff = 0;
            for(int i = 0; i<len; i++){
            diff += abs(tar-num[i]);
            }
            cout<<diff<<endl;
        }
        else{
            int tar1 = num[len/2];
            int tar2 = num[len/2 - 1];
            long long diff1 = 0, diff2 = 0;
            for(int i = 0; i<len; i++){
            diff1 += abs(tar1-num[i]);
            diff2 += abs(tar2-num[i]);
            }
            cout<<min(diff1,diff2)<<endl;
        }
        
        
    }
 
    return 0;
}