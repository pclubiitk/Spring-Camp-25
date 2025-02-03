#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    set<int> loc;
    loc.insert(0);
    loc.insert(x);
    map<int, set<pair<int,int>>> map;
    map[x].insert({0, x});

    for(int i = 0; i < n; i++)
    {
        int p = arr[i];
        auto it = loc.lower_bound(p);
        int r = *it;       
        it--;
        int l = *it;       

        int oldLen = r - l;
        auto &oldSet = map[oldLen];
        oldSet.erase({l, r});
        if(oldSet.empty())
        {
            map.erase(oldLen);
        }

        int leftLen = p - l;
        int rightLen = r - p;
        map[leftLen].insert({l, p});
        map[rightLen].insert({p, r});
        loc.insert(p);

        cout << (*(--map.end())).first << " ";
    }
}