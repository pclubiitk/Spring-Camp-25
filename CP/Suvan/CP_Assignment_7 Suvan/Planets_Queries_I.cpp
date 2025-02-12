#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

vi num;
int mat[200005][20];

void binary_lifting(int n){
    
    memset(mat, -1, sizeof(mat));
    for(int i = 1; i<=n; i++){
        mat[i][0] = num[i]; 
    }
    for(int i = 1; i<20; i++){
        for(int j = 1; j<=n; j++){
            if(mat[j][i-1]!=-1){
            mat[j][i] = mat[mat[j][i-1]][i-1]; 
            }
            else mat[j][i] = -1;
        }
    }

}

int ans(int start, int k){
    for(int i = 19; i>=0; i--){
        if(k & (1<<i)){
            start = mat[start][i];
        }
    }
    return start;
}
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;
        num.resize(n+1);
        for(int i = 1; i<=n; i++){
            cin>>num[i];
        }

        binary_lifting(n);
        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            cout<<ans(a,b)<<endl;
        }

    }

    return 0;
}
