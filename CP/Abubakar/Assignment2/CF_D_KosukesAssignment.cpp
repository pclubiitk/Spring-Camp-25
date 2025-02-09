#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vdc vector<vector<char>>
#define vdll vector<vector<ll>>
#define vll vector<ll>
#define vc vector<char>
#define vpll vector<pair<ll>>
#define ss second
#define ff first
#define ld long double
#define loop(i,n) for(int i=0;i<n;i++)
#define lop(i,n) for(int i=1;i<=n;i++)


int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n, 0);
        for (auto& x : v)cin >> x;
        ll sum = 0;
        set<ll>s;
        s.insert(0);
        ll ct = 0;
        for (auto x : v)
        {
            sum += x;
            if (s.find(sum) == s.end())
            {
                s.insert(sum);
            }
            else {
                s.clear();
                s.insert(sum);
                ct++;//like number of times it clears is the number of disinct seg
            }


        }
        cout << ct << endl;
    }
}
