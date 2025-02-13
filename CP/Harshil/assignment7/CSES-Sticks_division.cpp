#include <bits/stdc++.h>
using namespace std;

// int rec(int n, int k, int arr[], int prefix[], int l, int r) 
// {
//     if(l > r)
//         return 0;
        
//     if(l == r) 
//     {
//         return prefix[r] - (l == 0 ? 0 : prefix[l-1]);
//     }
    
//     int total = prefix[r] - (l == 0 ? 0 : prefix[l-1]);
//     int target = total / 2 + (l == 0 ? 0 : prefix[l-1]);
    
//     int *it = lower_bound(prefix + l, prefix + r + 1, target);
//     int pos = it - prefix;
    
    
//     if(pos == l && l < r)
//         pos++;
//     if(pos > r)
//         pos = r;
    
//     int left_cost = rec(n, k, arr, prefix, l, pos - 1);
//     int right_cost = rec(n, k, arr, prefix, pos, r);
    
//     return total + left_cost + right_cost;
// }

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) 
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    

    priority_queue<int> pq;
    pq.push(arr[0]);
    pq.push(arr[0]);
    while(!pq.size())
    {

    }
    
    cout << ans - n<< endl;
    return 0;
}