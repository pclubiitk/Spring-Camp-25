#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)
void solve()
{
   int n;
   cin >> n;
   vector<int> h(n + 1, 0);
   f(i,1,n+1){
    cin >> h[i];
   }
   
   vector<int> arr(n + 1);
   arr[2] = abs(h[2] - h[1]);
   f(i,3,n+1){
    arr[i] = min(arr[i - 1] + abs(h[i] - h[i - 1]),arr[i - 2] + abs(h[i] - h[i - 2]));
   }
   cout << arr[n] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}