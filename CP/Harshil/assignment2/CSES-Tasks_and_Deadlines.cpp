#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int reward = 0, current_time = 0;
    for(int i = 0; i < n; i++)
    {
        current_time += arr[i].first;
        reward += arr[i].second - current_time;
    }
    cout << reward << endl;
}