#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n;
    cin>>x>>n;
    auto cmp=[](const vector<int>& v1,const vector<int>& v2){
        return v1[0]<v2[0];
    };
    set<vector<int>,decltype(cmp)> a(cmp);
    multiset<int> lens;
    lens.insert(x);
    a.insert({0,x,x}); 
    REP(i,0,n-1){
        int val;
        cin>>val;
        auto it=a.lower_bound({val,0,0});
        it--;
        vi cur=*it;
        vi new1={cur[0],val,val-cur[0]};
        vi new2={val,cur[1],cur[1]-val};
        a.erase(it);
        a.insert(new1);
        a.insert(new2);
        lens.erase(lens.find(cur[2]));
        lens.insert(new1[2]);
        lens.insert(new2[2]);
        cout<<*(lens.rbegin())<<" ";
        /* int curMax=0;
        for(auto el: a){
            curMax=max(curMax,el[2]);
        }
        cout<<curMax<<" "; */

    }
    return 0;
}