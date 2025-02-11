#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
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

void mat_mul(vector<vector<long long> >& A, vector<vector<long long> >& B, vector<vector<long long> >& C, int size) {
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int k= 0; k < size; k++) {       
            for (int j = 0; j < size; j++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
}

void matrixExponentiation(vector<vector<ll> >& mat, ll n, int size) {
    vector<vector<ll> > result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }

    while (n > 0) {
        if (n % 2 == 1) {
            vector<vector<ll> > temp(size, vector<ll>(size, 0));
            mat_mul(result, mat, temp, size);
            result = temp;
        }
        vector<vector<ll> > temp(size, vector<ll>(size, 0));
        mat_mul(mat, mat, temp, size);
        mat = temp;

        n /= 2;
    }
    mat = result;
}

int main() {
    fast_io();

    int test = 1; 
    //cin>>test; 
    while(test--) {
        ll n;
        cin >> n;  
        if(n==0){
            cout<<"0"<<endl;
            continue;
        } 

        vector<vector<ll> > mat(2, vector<ll>(2, 0));
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        matrixExponentiation(mat, n-1, 2); 

        cout << mat[0][0] << endl;
    }

    return 0;
}
