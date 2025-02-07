#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vdll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define inf (ll)1e12+5

const ll N = 1000010;

vll divs(N);
vdll res(11, vll(N, 0));

void sieve() {
    for (ll i = 2; i < N; i++) {
        if (!divs[i]) {
            for (ll j = i; j < N; j += i) divs[j]++;
        }
    }
    for (ll n = 0; n <= 10; n++) {
        for (ll i = 1; i < N; i++) {
            res[n][i] = res[n][i - 1] + (divs[i] == n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        cout << res[n][b] - res[n][a - 1] << endl;
    }
}
