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
const int maxN = 1e5;

int n, m, components, largest, ds[maxN+1];
 
int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}
 
bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return false;
    if(ds[u] < ds[v]) swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}
 
int main(){
    cin >> n >> m;
    rep(i, 0, n) {
        ds[i] = -1;
    }
    components = n;
    largest = 1;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(merge(a, b)){
            components--;
            largest = max(largest, -ds[find(a)]);
        }
        cout << components << " " << largest << endl;
    }
}