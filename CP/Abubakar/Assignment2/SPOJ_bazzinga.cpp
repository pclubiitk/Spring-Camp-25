#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back

const ll LIMIT = 2000000, N = 1000000;
vll res;

void sieve() {
    vector<bool> is_prime(N + 1, true);
    vll primes;

    for (ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= N; j += i) is_prime[j] = false;
        }
    }

    vll temp;
    for (ll i = 0; i < primes.size(); i++) {
        for (ll j = i + 1; j < primes.size(); j++) {
            ll p = primes[i] * primes[j];
            if (p > LIMIT) break;
            temp.pb(p);
        }
    }

    sort(temp.begin(), temp.end());
    res.assign(temp.begin(), temp.begin() + min(LIMIT, (ll)temp.size()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        cout << res[k - 1] << "\n";
    }
    return 0;
}
