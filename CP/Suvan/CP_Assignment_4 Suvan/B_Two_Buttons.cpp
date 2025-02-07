// #include <bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;
// typedef set<int> s;
// #define sz(a) int((a).size())
// #define pb push_back
// #define all(c) (c).begin(), (c).end()
// #define present(c, x) ((c).find(x) != (c).end())

// void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }
// int cnt = 0;
// s visited;
// void dfs(int a, int b){
//     if(a<0 || present(visited,a)) return;
//     if(a==b) return;

//     visited.insert(a);
//     cnt++;

//     dfs(2*a,b);
//     dfs(a-1,b);
// }
// int main() {
//     fast_io();

//     int test = 1;
//     //cin >> test;
//     while(test--) {
//         int a,b;
//         cin>>a>>b;
//         dfs(a,b);
//         cout<<cnt<<endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

unordered_set<int> visited;

int dfs(int n, int m) {
    if (n > m) {
        return n - m;
    }
    if (n == m) return 0;
    if (visited.find(n) != visited.end()) return INT_MAX;
    visited.insert(n);

    int option1 = 1 + dfs(2 * n, m);
    int option2 = 1 + dfs(n - 1, m);
    int result = min(option1, option2);

    visited.erase(n);
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    visited.clear();
    
    int result = dfs(n, m);
    cout << result << endl;

    return 0;
}
