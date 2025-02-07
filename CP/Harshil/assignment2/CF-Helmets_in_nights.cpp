#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) 
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(abs(a[i] - b[j]) <= 1) 
            {
                ans++;
                b[j] = -1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}