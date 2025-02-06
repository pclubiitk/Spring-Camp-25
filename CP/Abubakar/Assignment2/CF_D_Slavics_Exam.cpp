#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vdc vector<vector<char>>
#define vdll vector<vector<ll>>
#define vll vector<ll>
#define vc vector<char>
#define vpll vector<pair<ll>>
#define ss second
#define ff first
#define ld long double
#define loop(i,n) for(int i=0;i<n;i++)
#define lop(i,n) for(int i=1;i<=n;i++)

int main()
{
    ll n;
    cin >> n;
    while(n--) {
        string s, t;
        cin >> s >> t;
        ll ind = 0;
        ll n = s.size();
        ll m = t.size();
        
        loop(i, n) {
            if(ind >= m) 
            {  
                if(s[i] == '?') s[i] = 'z';
                continue;
            }
            
            if(s[i] == '?') 
            {
                s[i] = t[ind];
                ind++;
            } 
            else if(s[i] == t[ind]) {
                ind++;
            }
        }
        

        if(ind >= m) 
        {
            cout << "YES\n" << s << endl;
        } 
        else {
            cout << "NO"<<endl;
        }
    }
    
}
