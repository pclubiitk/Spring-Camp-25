#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n); 
 
    for (int i = 0; i < n; i++) {
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