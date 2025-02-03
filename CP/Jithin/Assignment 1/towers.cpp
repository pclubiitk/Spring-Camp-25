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
    int n;
    cin>>n;
    vector<int> siz(n);
    REP(i,0,n-1) cin>>siz[i];
    vector<int> towHead;
    REP(i,0,n-1){
        auto it=upper_bound(towHead.begin(),towHead.end(),siz[i]);
        if(it==towHead.end()){
            towHead.emplace_back(siz[i]);
        } else {
            *it=siz[i];
        }
    }
    cout<<towHead.size();
    return 0;
}