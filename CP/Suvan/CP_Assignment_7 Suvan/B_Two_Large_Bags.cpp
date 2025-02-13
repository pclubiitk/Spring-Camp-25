#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
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
    cin >> test; 
    while(test--) {
        int n;
        cin>>n;
        vi num(n);
        map<int,long long> cnt;
        for(int i = 0; i<n; i++){
            cin>>num[i];
            cnt[num[i]]++;
        }
        map<int,long long> fin;
        int flag1 = 1;
        int flag2 = 1;
        for(int i = 0; i<n; i++){
            if(cnt[num[i]]%2){
                fin[num[i]] = cnt[num[i]];
                flag1 = 0;
            }
            if(cnt[num[i]]%2){
                if(i>0){
                    if((cnt[num[i-1]]>2 && cnt[num[i-1]]%2 && abs(num[i-1]-num[i])==1)) flag2 =1 ;
                    else flag2 = 0;
                }
                if(i<n-1){
                    if((cnt[num[i+1]]>2 && cnt[num[i+1]]%2 && abs(num[i+1]-num[i])==1 )) flag2 =1;
                    else flag2 = 0;
                }
            }
        }
        if(flag1){
            cout<<"YES"<<endl;
            continue;
        }
        if(flag2){
            cout<<"NO"<<endl;
            continue;
        }
        continue;
    }

    return 0;
}

  