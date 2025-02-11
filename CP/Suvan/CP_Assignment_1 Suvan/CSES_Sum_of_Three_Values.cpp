#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
typedef vector< pair<int,int> > pii;
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
    //cin >> test;
    while(test--) {
        int len, tar;
        cin>>len>>tar;
        vi num;
        pii index;
        for(int i = 0; i<len; i++){
            int a;
            cin>>a;
            num.push_back(a);
            index.push_back(make_pair(a,i+1));
        }
        sort(all(num));
        sort(all(index));
        bool flag  = false;
        for(int i = 0; i<sz(num) && !flag; i++){
            int t = tar - num[i];
            int l = i+1, r = sz(num)-1;
            while(l<r){
                int sum = num[l] + num[r];
                if(sum == t){
                    cout<<index[i].second<<" "<<index[l].second<<" "<<index[r].second<<endl;
                    flag = true;
                    break;
                }
                else if(sum<t){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        if(!flag){
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
 
    return 0;
}