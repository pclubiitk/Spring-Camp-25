#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n; i++)

vector<int> parent(200005), size1(200005,1);
int max_size = 1;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

void union_func(int a, int b) {
    
    int x = find(a);
    int y = find(b);
    
    if(x != y) {
        if (size1[x] < size1[y]) swap(x, y); 
        parent[y] = x;
        size1[x] += size1[y];
        max_size = max(max_size, size1[x]); 
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) parent[i] = i;
    int count = n; 

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        if (find(a) != find(b)) {
            union_func(a,b);
            count--; 
        }
        
        cout << count << ' ' << max_size << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
