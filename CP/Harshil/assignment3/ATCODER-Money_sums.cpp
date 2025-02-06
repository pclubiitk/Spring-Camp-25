#include <bits/stdc++.h>
using namespace std;

void rec(int current, const vector<int>& arr, int idx, vector<bool>& reachable)
{
    reachable[current] = true;
    for (int i = idx; i < arr.size(); i++) 
    {
        int next = current + arr[i];
        if (next < reachable.size() && !reachable[next]) 
        {
            rec(next, arr, i + 1, reachable);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    vector<bool> reachable(total + 1, false);
    rec(0, arr, 0, reachable);
    int count=0;
    for(int i=1;i<=total;i++)
    {
        if(reachable[i])
        {
            count++;
        }
    }
    cout<<count<<endl;
    for (int s = 0; s <= total; s++)
    {
        if (reachable[s]&&s!=0)
            cout << s << " ";
    }
    cout << endl;
    return 0;
}
