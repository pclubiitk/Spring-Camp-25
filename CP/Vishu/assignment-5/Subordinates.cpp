#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

vector<vector<int>> adj(200005);
vector<int> size1(200005);

int calc(int node) {
    if (adj[node].empty()) {
        return 1;
    } else {
        for (int child : adj[node]) {
            size1[node] += calc(child);
        }
    }
    return size1[node] + 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    calc(1);
    for (int i = 1; i <= n; i++) {
        cout << size1[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
