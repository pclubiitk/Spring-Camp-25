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
long long pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
#define MOD 1000000007
#define PHI_MOD (MOD - 1)  
int main() {
    fast_io();
 
    int test = 1;
    //cin >> test;
    while(test--) {
        int n;
        cin>>n;
        long long prod =1,sum=1,num=1;
        for(int i = 0; i<n; i++){
            long long a,b;
            cin>>a>>b;
            num = num*(b+1)%MOD;
            b = pow(b,1,PHI_MOD);
            prod = prod*pow(a,b,MOD)%MOD;
            long long num = pow(a,b+1,MOD)-1;
            long long den = pow(a-1,MOD-2,MOD);
            sum = (sum*num%MOD)*den%MOD;
        }
        long long e = pow(num,1,PHI_MOD);
        prod = pow(prod,e/2,MOD);
        cout<<num<<" "<<sum<<" "<<prod<<endl;
    }
 
    return 0;
}