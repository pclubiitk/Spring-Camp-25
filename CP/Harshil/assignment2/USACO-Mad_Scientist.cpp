// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cstdint>
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ifstream inputFile;
    
    int n;
    inputFile >> n;
    string s1, s2;
    inputFile >> s1 >> s2;
    inputFile.close();
    vector<bool> s(n);
    for(int i = 0; i < n; i++)
    {
        if(s1[i] == s2[i])
        {
            s[i] = true;
        }
        else
        {
            s[i] = false;
        }
    }
    int count = 0;
    bool prev = true;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == false)
        {
            if(prev == true)
            {
                count++;
            }
            prev = false;
        }
        else
        {
            prev = true;
        }
    }
    ofstream outputFile("breedflip.out");
    outputFile << count << endl;
    outputFile.close();

    cout << count << endl;
    return 0;
}