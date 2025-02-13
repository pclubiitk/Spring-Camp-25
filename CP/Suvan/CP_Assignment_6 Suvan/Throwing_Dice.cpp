#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

typedef vector<vector<long long > > matrix;
const long long MOD  = 1e9+7;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

matrix mat_mul(matrix A,matrix B){
    int n = A.size();
    matrix res(n, vector<long long>(n, 0));

    for(int i = 0; i<n; i++){
        for(int k = 0; k<n; k++){
            for(int j = 0; j<n; j++){
                res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]%MOD)))%MOD;
            }
        }
    }

    return res;
}

matrix binary_exponentiation(matrix A, long long exp){
    int n = A.size();
    matrix res(n,vector<long long> (n,0));
    for(int i = 0; i<n; i++){
        res[i][i] = 1;
    }

    while(exp>0){
        if(exp%2){
            exp -= 1;
            res = mat_mul(res,A);
        }
        A = mat_mul(A,A);
        exp = exp/2;
    }
    return res;
}
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        long long a;
        cin>>a;
        vector<int> in;
        in.push_back(16);
        in.push_back(8);
        in.push_back(4);
        in.push_back(2);
        in.push_back(1);
        in.push_back(1);
     
        matrix ans (6,vector<long long>(6,0));
        for (int i = 0; i < 6; i++) {

        if (i == 0) {
        for (int j = 0; j < 6; j++) {
            ans[i][j] = 1; 
        }
        } else {
            ans[i][i - 1] = 1; 
        }
        }

        if(a<=6){
            vector<int> dp(a+1,0);
            dp[0] = 1;
            for(int i = 1; i<=a; i++){
                for(int j = 1; j<=6; j++){
                    if(i-j>=0){
                        dp[i] = (dp[i] + dp[i-j])%MOD;
                    }
                   
                }
            }
            cout<<dp[a]<<endl;
            return 0;
        }

        ans = binary_exponentiation(ans,a-5);
        long long cnt = 0;
        for(int i = 0; i<6; i++){
            cnt = (cnt + (ans[0][i]*in[i])%MOD)%MOD;
        }
        cout<<cnt<<endl;

    }

    return 0;
}

