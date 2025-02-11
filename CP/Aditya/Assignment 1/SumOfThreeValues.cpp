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
    int n, x;
    cin >> n >> x;
    vi a(n);
    unordered_map<int, vector<int>> index; 
 
    rep(i, 0, n) {
        cin >> a[i];
        index[a[i]].push_back(i); 
    }
 
    sort(all(a));
    bool flag = false;
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - a[i] - a[j];
            auto it = lower_bound(a.begin() + j + 1, a.end(), target);
            if (it != a.end() && *it == target) {
                flag = true;
 
                int idx1 = index[a[i]].back();
                index[a[i]].pop_back();
                int idx2 = index[a[j]].back();
                index[a[j]].pop_back();
                int idx3 = index[*it].back();
                index[*it].pop_back();
 
                cout << idx1 + 1 << " " << idx2 + 1 << " " << idx3 + 1 << endl;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) cout << "IMPOSSIBLE";
}