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
#define MOD 1000000007
#define PHI_MOD (MOD - 1)  
 
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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
 
        long long exponent = pow(b, c, PHI_MOD); 
 
        if (exponent == 0 && b != 0) {
            exponent = PHI_MOD;
        }
 
        long long result = pow(a, exponent, MOD);
 
        cout << result << endl;
    }
 
    return 0;
}