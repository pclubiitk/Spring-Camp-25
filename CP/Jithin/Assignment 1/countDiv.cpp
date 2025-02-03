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
#define rep(i,a,b) for (int i = a; i <= b; i++)



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        vector<int> primeF;
        if(x==1) {
            cout<<"1\n";
            continue;
        }
        for(int i=2; i*i<=x;++i){
            int count=0;
            while(x%i==0){
                ++count;
                x/=i;
            }
            primeF.emplace_back(count);
        }
        if(x>1) primeF.emplace_back(1);
        ll prod=1;
        for(auto el: primeF){
            prod*=(el+1);
        }
        cout<<prod<<"\n";
    }
    return 0;
}