#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s1, s2;
        cin >> s1 >> s2;
 
        int index = 0;
        for (int i = 0; i < s1.length() && index < s2.length(); i++) 
        {
            if (s1[i] == '?' || s1[i] == s2[index]) 
            {
                s1[i] = s2[index];
                index++;
            }
        }
        if (index == s2.length()) 
        {
            cout << "YES" << endl;
            cout << s1 << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}