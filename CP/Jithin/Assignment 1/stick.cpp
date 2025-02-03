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
    vi sticks(n);
    REP(i,0,n-1){
        cin>>sticks[i];
    }
    sort(sticks.begin(),sticks.end());
    if(n%2){
        ll sum=0;
        int median=sticks[n/2];
        for(int el: sticks) sum+=abs(median-el);
        cout<<sum;
    } else {
        int m1=sticks[n/2-1];
        int m2=sticks[n/2];
        ll sum1=0,sum2=0;
        for(int el: sticks){
            sum1+=abs(el-m1);
            sum2+=abs(el-m2);
        }
        cout<<max(sum1,sum2);
    }
    return 0;
}