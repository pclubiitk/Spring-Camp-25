#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int total_time = 0, max_time = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total_time += arr[i];
        max_time = max(max_time, arr[i]);
    }
    if(max_time > total_time - max_time)
    {
        cout << 2 * max_time << endl;
    }
    else
    {
        cout << total_time << endl;
    }
}