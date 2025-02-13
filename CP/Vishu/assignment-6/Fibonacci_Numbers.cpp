#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

void multiply(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2) {
    vector<vector<ll>> mat3(2, vector<ll>(2));
    mat3[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    mat3[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    mat3[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    mat3[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    mat1 = mat3;
}

void binexp(vector<vector<ll>> &mat1, ll n) {
    if (n == 0 || n == 1) return;
    vector<vector<ll>> mat2 = {{1, 1}, {1, 0}};
    binexp(mat1, n / 2);
    multiply(mat1, mat1);
    if (n % 2 != 0) multiply(mat1, mat2);
}

ll solve(ll n) {
    if (n <= 1) return n;
    vector<vector<ll>> mat1 = {{1, 1}, {1, 0}};
    binexp(mat1, n - 1);
    return mat1[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll test = 1;
    // cin >> test;
    while (test--) {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
