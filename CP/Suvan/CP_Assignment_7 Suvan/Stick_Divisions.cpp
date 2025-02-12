#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {

    int x, n;
	cin >> x >> n;
	priority_queue<int, vector<int>, greater<int> > PQ;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		PQ.push(a);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();
		PQ.push(a + b);
		ans += a + b;
	}

	cout << ans << "\n";

    }

    return 0;
}