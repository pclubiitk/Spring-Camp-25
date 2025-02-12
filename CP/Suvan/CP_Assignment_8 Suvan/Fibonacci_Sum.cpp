#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())


typedef long long ll;
const ll MOD = 1e9 + 7;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void mat_mul(vector<vector<ll> > &A, vector<vector<ll> > &B, vector<vector<ll> > &C, int size) {
    vector<vector<ll> > temp(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                temp[i][j] = (temp[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    C = temp;
}

void matrixExponentiation(vector<vector<ll> > &mat, ll n, int size) {
    vector<vector<ll> > result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++) {
        result[i][i] = 1; 
    }

    vector<vector<ll> > base = mat; 
    while (n > 0) {
        if (n % 2 == 1) {
            mat_mul(result, base, result, size);
        }
        mat_mul(base, base, base, size);
        n /= 2;
    }

    mat = result;
}

ll fib(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<vector<ll> > mat(2, vector<ll>(2, 0));
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    matrixExponentiation(mat, n - 1, 2);
    return mat[0][0]; 
}

int main() {
    fast_io();

    int test;
    cin >> test; 
    while (test--) {
        ll n, m;
        cin >> n >> m;

        ll result = (fib(m + 2) - fib(n + 1) + MOD) % MOD; 
        cout << result << endl;
    }

    return 0;
}

