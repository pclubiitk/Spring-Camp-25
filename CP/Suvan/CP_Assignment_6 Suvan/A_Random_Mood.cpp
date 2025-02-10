#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

typedef vector<vector<double> > matrix;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


matrix mat_mul(matrix A, matrix B){
    int n = A.size();
    matrix c(n,vector<double>(n,0));
    for(int i = 0; i<n; i++){
        for(int k = 0; k<n; k++){
            for(int j = 0; j<n; j++){
                c[i][j] = (c[i][j] + (A[i][k]*B[k][j]));
            }
        }
    }
    return c;
}
matrix matrix_exponentiation(matrix res, long long k){
    int n = res.size();
    matrix temp(n,vector<double>(n,0));
    for(int i = 0; i<n; i++){
        temp[i][i] = 1;
    }
    while(k>0){
        if(k%2){
            k-=1;
            temp = mat_mul(temp,res);
        }
        k/=2;
        res = mat_mul(res,res);
    }
    return temp;
}
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n;
        double p;
        cin>>n>>p;
        matrix ans;
        ans.assign(2,vector<double>(2,0));
        ans[0][0] = 1-p;
        ans[0][1] = p;
        ans[1][0] = p;
        ans[1][1] = 1-p;

        ans = matrix_exponentiation(ans,n);
        cout<<fixed<<setprecision(10)<<ans[0][0]<<endl;
    }

    return 0;
}