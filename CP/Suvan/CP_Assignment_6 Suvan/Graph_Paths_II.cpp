#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

typedef vector<vector<long long> > matrix;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


matrix mat_mul(matrix A, matrix B){
    int n = A.size();
    matrix c(n,vector<long long>(n,LLONG_MAX));
    for(int i = 0; i<n; i++){
        for(int k = 0; k<n; k++){
            for(int j = 0; j<n; j++){
                if (A[i][k] != LLONG_MAX && B[k][j] != LLONG_MAX && A[i][k] + B[k][j] < LLONG_MAX) 
                c[i][j] = min(c[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return c;
}
matrix matrix_exponentiation(matrix res, long long k){
    int n = res.size();
    matrix temp(n,vector<long long>(n,LLONG_MAX));
    for(int i = 0; i<n; i++){
        temp[i][i] = 0;
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
        int n,m,k;
        cin>>n>>m>>k;
        matrix mat(n,vector<long long>(n,LLONG_MAX));
        for(int i = 0; i<m; i++){
            int a,b,c;
            cin>>a>>b>>c;
            mat[a-1][b-1] = min (mat[a-1][b-1],(long long)c);
        }
        mat = matrix_exponentiation(mat,k);
        if(mat[0][n-1]!=LLONG_MAX)
        cout<<mat[0][n-1]<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}


