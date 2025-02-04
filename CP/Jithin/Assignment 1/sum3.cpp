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

bool allDistinct(int x,int y, int z){
    return x!=y && y!=z && z!=x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<pi> a(n);
    REP(i,0,n-1) {
        int y;
        cin>>y;
        a[i]={y,i+1};
    }
    sort(a.begin(),a.end());
    REP(i,0,n-3){
        int left=x-a[i].F;
        if(left<2) continue;
        REP(j,i+1,n-2){
            int nowLeft=left-a[j].F;
            if(nowLeft<1) continue;
           auto it=lower_bound(a.begin()+j+1,a.end(),pi {nowLeft,0});
           if(it!=a.end() && it->F==nowLeft){
                cout<< a[i].S<<" "<<a[j].S<<" "<<it->S;
                return 0;
           }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}