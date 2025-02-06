#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        vector<ll> v(s.length());
        vector<ll> xory(s.length());
        ll xore = 0;

      
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'P')
                v[i] = 80;
            else if (s[i] == 'C')
                v[i] = 67;
            else if (s[i] == 'l')
                v[i] = 108;
            else if (s[i] == 'u')
                v[i] = 117;
            else if (s[i] == 'b')
                v[i] = 98;

            xore ^= v[i];
            xory[i] = xore;
        }


        map<ll, ll> mp;
        mp[0] = 1; 
        ll ct = 0;

     
        for (int i = 0; i < xory.size(); i++)
        {
            if (mp.count(xory[i]))
            {
                ct += mp[xory[i]];}
            mp[xory[i]]++; 
        }

        cout << ct << endl;
    }
}
