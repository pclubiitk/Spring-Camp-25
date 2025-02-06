#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
    cint(n);
    vector<pi> a(n);
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& c, const pair<int, int>& b) {
        return c.second < b.second; 
    });
    int time = a[0].second, count = 1;
    rep(i, 1, n) {
        if (a[i].first >= time) {
            count++;
            time = a[i].second;
        }
    }
    cout << count << endl;
}