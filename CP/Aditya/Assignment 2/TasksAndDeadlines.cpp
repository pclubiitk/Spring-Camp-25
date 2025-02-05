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
    vector<pi> tasks(n); 
 
    rep(i, 0, n) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end()); 
    ll current_time = 0;
    ll total_reward = 0; 
    for (auto& task : tasks) {
        int duration = task.first;
        int deadline = task.second; 
        current_time += duration; 
        total_reward += deadline - current_time; 
    } 
    cout << total_reward << endl;
    return 0;
}