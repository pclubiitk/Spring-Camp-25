#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
#define MOD 1000000007
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        int h,w;
        cin>>h>>w;
        vector<string> matrix(h);
        for(int i = 0; i<h; i++){
            cin>>matrix[i];
        }
        vector<vector<int> > count(h+1,vi (w+1,0));
        count[1][1] = 1;
        for(int i = 1; i<=h; i++){
            for(int j = 1; j<=w; j++){
                if(i==1 && j==1) continue;
                if(matrix[i-1][j-1]=='#') continue;
                else count[i][j] = (count[i-1][j] + count[i][j-1])%MOD;
            }
        }
        cout<<count[h][w]%MOD<<endl;
    }
    return 0;
}

  