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

const int MAXN = 3e5 + 5;

int parent[MAXN], sizes[MAXN];
bool alive[MAXN];

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
    alive[v] = true;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<int> result;
    int components = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int person = order[i];
        components++;
        alive[person] = true;
        
        for (auto [u, v] : queries) {
            if (alive[u] && alive[v] && find_set(u) != find_set(v)) {
                union_sets(u, v);
                components--;
            }
        }
        
        result.push_back(components);
    }
    
    reverse(result.begin(), result.end());
    
    for (int count : result) {
        cout << count << " ";
    }
    cout << "\n";
    
    return 0;
}
