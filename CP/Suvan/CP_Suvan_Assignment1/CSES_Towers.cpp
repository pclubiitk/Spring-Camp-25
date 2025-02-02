#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main() {
    fast_io();
 
    int test = 1;
 
    while(test--) {
        int n;
        cin>>n;
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        reverse(all(num));
        int ans = 0;
        s last_element;
        for(int i = 0; i<n; i++){
            auto it = last_element.lower_bound(num[i]);
            if(it==last_element.begin()){
                ans++;
                last_element.insert(num[i]);
            }
            else{
                it = prev(it);
                last_element.erase(it);
                last_element.insert(num[i]);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}