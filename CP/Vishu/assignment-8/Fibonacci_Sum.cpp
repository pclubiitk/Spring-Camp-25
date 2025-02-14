#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n; i++)

void multiply(ll a[2][2], ll b[2][2]) {
    ll x = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    ll y = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    ll z = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    ll w = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    
    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;
}

ll fib(ll n) {
    if (n == 0)
        return 0;
    
    ll a[2][2] = {{1,1},{1,0}};
    func(a, n - 1);
    return a[0][0];
}

void func(ll a[2][2], ll n) {
    if (n == 0 || n == 1)
        return;
    ll b[2][2] = {{1,1},{1,0}};
    func(a, n / 2);
    multiply(a, a);
    if (n % 2 != 0)
        multiply(a, b);
}

void solve() {
    ll n, m, result;
    cin >> n >> m;
    result = (fib(m + 2) - fib(n + 1)) % mod;
    if (result < 0){
        result += mod;
    }
    cout << result << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}