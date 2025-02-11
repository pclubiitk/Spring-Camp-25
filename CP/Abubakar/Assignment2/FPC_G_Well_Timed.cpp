#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int main() {
    ll n, sum = 0, maxc = 0, sm = 0;
    cin >> n;
    vll v(n);
    for (auto &x : v) {
        cin >> x;
        sum += x;
        if (x > maxc) {
            sm = maxc;
            maxc = x;
        } else if (x > sm) {
            sm = x;
        }
    }
    cout << min(maxc * 2 + max(sum - maxc - sm, maxc), max(sum - maxc - sm, sm) + 2 * maxc) << endl;
}
// gave TLE :(
