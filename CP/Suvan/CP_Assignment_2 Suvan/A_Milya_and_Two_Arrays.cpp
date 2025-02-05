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
    cin >> test;
    while(test--) {
        int n;
        cin>>n;
        s num1;
        s num2;
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            num1.insert(a);
        }
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            num2.insert(a);
        }
        if(num1.size()>=2 && num2.size()>=2){
            cout<<"YES"<<endl;
        }
        else if((num1.size()==1 && num2.size()>=3) || (num2.size()==1 && num1.size()>=3)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}