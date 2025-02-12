#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // No of zeroes=t, no: of ones=x, no: of twos=y, no: of threes=z.
    // Prob. of choosing a specific dish=1/n.
    // dp(x,y,z) represent the expected no: of operations in such a situation
    // dp(0,0,0)=0.
    // dp(x,y,z)=1(As one operation performed to go to next step) +
    // x/n * dp(x-1,y,z)+y/n * dp(x+1,y-1,z)+ z/n*dp(x,y+1,z-1)+t/n*dp(x,y,z).
    int n;
    cin>>n;
    vi req(3);
    rep(i,0,n-1){
        int x;
        cin>>x;
        ++req[x-1];
    }
    cout<<setprecision(13);
    //int maxEl=*max_element(req.begin(),req.end());
    double dp[n+1][n+1][n+1];
    dp[0][0][0]=0;
    rep(sum,1,n){
        for(int x=sum;x>=0;--x){
            for(int y=sum-x;y>=0;--y){
                int z=sum-x-y;
                if(z<0) continue;
                dp[x][y][z]=(double)n/sum+(double)x/sum*dp[max(x-1,0)][y][z]+(double)y/sum*dp[x+1][max(y-1,0)][z]+(double)z/sum*dp[x][y+1][max(z-1,0)];
            }
        }
    }
    cout<<dp[req[0]][req[1]][req[2]];   
    return 0;
}