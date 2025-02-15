#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define tr(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while(a--)
#define cint(n) int n; cin >> n;
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    int n, k;
    cin >> n >> k;
    vector<pi> movies(n);
    rep(i, 0, n) {
        cin >> movies[i].second >> movies[i].first;
    }    
    sort(all(movies));    
    multiset<int> end_times;
    rep(i, 0, k) end_times.insert(0);    
    int count = 0;
    tr(movie, movies) {
        auto it = end_times.upper_bound(movie.second);
        if (it != end_times.begin()) {
            --it;
            end_times.erase(it);
            end_times.insert(movie.first);
            ++count;
        }
    }    
    cout << count << endl;    
}
