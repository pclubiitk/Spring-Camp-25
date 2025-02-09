#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
    cint(t);
    w(t) {
        int n, p;
        cin >> n >> p;
        vector<pi> a(n);
        rep(i, 0, n) {
            cin >> a[i].first;
        }
        rep(i, 0, n) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end(), [](const pi &a, const pi &b) {
            return a.second < b.second;
        });
        ll cost = p;
        int remaining = n-1, i = 0;
        while (remaining > 0) {
            if (a[i].second >= p) {
                cost += p;
                remaining--;
            }
            else {
                cost += a[i].second;
                remaining--;
                a[i].first--;
                if (a[i].first == 0) i++;
            }
        }
        cout << cost << endl;
    }
}