#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()

bool chk(const vector<ll> &arr, const ll k, ll ms) {

	ll ct = 0;

	ll cs = 0;

	for (const ll &x : arr) {
		if (x > ms) { return false; }

		if (cs + x > ms) {
			ct++;
			cs = 0;
		}
		cs += x;
	}
	if (cs > 0) { ct++; }

	return (ct <= k);
}

ll main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (ll &i : arr) { cin >> i; }

	ll l = *max_element(all(arr));
	ll r = accumulate(all(arr), 0LL);
	while (l < r) {
		ll mid = (l + r) / 2;
		if (chk(arr, k, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}