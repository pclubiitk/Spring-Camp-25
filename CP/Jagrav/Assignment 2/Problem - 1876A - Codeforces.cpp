#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<bitset>
#include<sstream>
 
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// find_by_order, order_of_key
 
typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<int64_t> vll;
typedef vector<string> vs;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int64_t>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<double>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<int64_t>>> vvvll;
typedef vector<vector<long double>> vvvld;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<vector<vector<char>>> vvvc;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef vector<vector<pair<ll,ll>>> vvpll;
typedef tuple<ll,ll,ll> tll;    
typedef vector<tll> vtll;
// typedef unordered_set us;
// typedef ordered_set os;
// typedef unordered_map um;
// typedef ordered_map om;

 
#define pb push_back
#define pob pop_back()
#define sz size()
#define ff first
#define ss second
#define PI 3.14159265359
#define M1 ll(998244353)
#define M2 ll(1e7)
#define M 2e5+5
#define MOD ll(1000000007)
#define INF 1500000000000000000
#define NINF -1500000000000000000
#define lp0(i,n) for(ll i=0;i<n;i++)
#define lp1(i,n) for(ll i=1;i<=n;i++)
#define lp(i,a,b) for(ll i=a; i<=b; i++)
#define rlp(i,a,b) for(ll i=a; i>=b; i--)
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define time_start auto start = chrono::high_resolution_clock::now();
#define time_stop auto stop = chrono::high_resolution_clock::now();
#define time_duration auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
#define time_print cout << "Time: "<< duration.count() << " microseconds" << endl;
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define reach cout<<"Reached!"<<endl;
#define sayn cout<<"NO"<<'\n';
#define sayy cout<<"YES"<<'\n';
 
//------Standard Functions------
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template<typename T>
T max2(T a,T b){
 
    return max(a,b);
}
template<typename T>
T min2(T a,T b){
 
    return min(a,b);
}

template<typename T>
T max3(T a,T b,T c){
 
    return max(a,max(b,c));
}
 
template<typename T>
T max4(T a,T b,T c,T d){
 
    return max(max(a,d),max(b,c));
}
template<typename T>
T min3(T a,T b,T c){
 
    return min(a,min(b,c));
}
 
template<typename T>
T min4(T a,T b,T c,T d){
 
    return min(min(a,d),min(b,c));
}
template <typename T>
T binex(T a, T b, T mod){
 
    T ans=1;
    a%=mod;
 
    while(b>0){
 
        if(b&1){
 
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}
 
template <class T>
ostream& operator<<(ostream &os, vector<T> a){
 
    //os<<"[ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"]"<<"\n";
    return os;
}
 
template <class T>
ostream& operator<<(ostream &os, set<T> a){
 
    //os<<"{ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os;
}
 
template <class T>
 
ostream& operator<<(ostream &os, multiset<T> a){
 
    //os<<"{ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os; 
}
template <class T,class Q>
ostream& operator<<(ostream &os, pair<T,Q> a){
 
    os<<"| ";
    os<<a.ff<<", "<<a.ss<<" ";
    return os<<"|";
}
template<class P,class Q, class T>
 
ostream& operator<<(ostream &os, tuple<P,Q,T> a){
 
    os<<"| "<<(get<0>(a))<<", "<<(get<1>(a))<<", "<<(get<2>(a))<<"|";
    return os;
}

ll mod_inverse(ll a, ll mod){
    ll ans=1; ll exp=mod-2;
    while((exp)>0){
        if((exp)&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod; 
        (exp)/=2;

    }
    return ans;
}

ll abs1(ll n){
    if(n<0){return n*(-1);}
    else return n;
}

ll gcd(ll a, ll b){
    while(b!=0){
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return(a/gcd(a,b))*b;
}

bool prime(ll n) {
    bool isPrime = true;
    if(n==0 || n==1){isPrime=false;}
    else{
        for(ll i=2; i*i<=n; ++i){
            if(n%i==0){isPrime = false;break;}
        }
    }
    return isPrime;
}

//---------Start--------
//-----Errorspect19-----



void precomp(){
 
    
 
}

//vpii dirs = {{-1,0},{0,1},{1,0},{0,-1}};


// int fun(int n){
    
// }

// ll n,m,k;
// vvb vis;
// vs g;

// void dfs(ll a, ll b){
//  if(min(a,b)<0 || a>=n || b>=m || g[a][b]=='X' || g[a][b]=='#' || vis[a][b]){
//      return;
//  }
//  vi(s[a][b]=1;
//  dfs(a+1,b);
//  dfs(a-1,b); 
//  dfs(a,b+1);
//  dfs(a,b-1);


//  if(k!=0){
//      g[a][b]='X'; k--;
//  }
//  return;
// }


// vvi adj(n); vi ind(n); 
// vi BFS(){
//  vi ordering;
//  queue<int> q; vb vis(n+1); vis[1]=1;
//  q.push(1);

//  while(!q.empty()){
//      int u=q.front();
//      ordering.pb(u);
//      q.pop();    
//      for(int v:adj[u]){
//          if(!vis[v]){
//              vis[v]=1;   q.push(v);
//          }
//      }
//  }
//  return ordering;
// }

// bool cmp(int a, int b){
//  return ind[a]<ind[b];
// }


void solve(){
    
    ll n,r; cin>>n>>r;
    vpll v(n);
    lp0(i,n){cin>>v[i].ss;}
    lp0(i,n){cin>>v[i].ff;}
    sort(v.begin(),v.end());
    ll rm=n-1,tl=r;
    lp0(i,n){
        if(v[i].ff>=r){break;}
        ll cnt=(rm<v[i].ss)?rm:v[i].ss;
        tl+=cnt*v[i].ff;
        rm-=cnt;
    }
    tl+=r*rm;
    o1(tl);

}


int main(){

    //time_start;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cout.tie(NULL);
    
    ll tt;
 
    cin>>tt;
 
    precomp();
 
    lp1(ii,tt){
 
        solve(); 

       
        
 
    }
    
    // time_stop
    // time_duration;
    // time_print;
}