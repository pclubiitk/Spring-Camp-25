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
    while(test--){

        int n;
        cin>>n;
        vi a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int cnt = 0;
        int i = 0;
        while(i<n){ 
            if(a[i]==1) {
                cnt++;
            }
            if(a[i+1]==0 && i+1<n) i+=2;
            else i+=1;

            if(i+1<n) i+=2;
            else i+=1;
            
        }
        cout<<cnt<<endl;
    }

    return 0;
}


