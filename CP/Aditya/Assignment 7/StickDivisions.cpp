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
#define INF 1e9
#define MOD 1000000007
const int MAX = 200001;

//priority queue has been used to avoid TLE

int main() {
    int x, n;
    cin >> x >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, 0, n) {
        cint(l);
        pq.push(l);
    }    
    ll cost = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }    
    cout << cost << endl;
    return 0;
}
