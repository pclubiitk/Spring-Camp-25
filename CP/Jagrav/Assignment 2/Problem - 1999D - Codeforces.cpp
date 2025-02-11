#include<bits/stdc++.h>
#include<climits>
using namespace std;
using ll = long long;
const int mxi = INT_MAX;
const ll mxll = LLONG_MAX;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define rvrep(i,a,b) for(ll i=n-1; i>=0; i--)

ll ab(ll i){
	if(i<0){return i*((ll)-1);}else{return i;}
}

ll min1(ll a, ll b){
	if(a<b){return a;}
	else{return b;}
}

ll max1(ll a, ll b){
	if(a>b){return a;}
	else{return b;}
}

ll sc(ll a){return a+1;}
ll pr(ll a){return a-1;}

ll l(ll a, ll b){
	return log(a)/log(b);
}

int ch(int a){
	char p = (char)a;
	return p;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		ll t; cin>>t;
		while(t--){
		string s,t; cin>>s>>t;
		ll m=t.size(),n=s.size();
		ll i=0,j=0;
		while(i<n && j<m){
			if(s[i]=='?'){
				s[i]=t[j];
			}
			if(s[i]==t[j]){
				i++; j++;
				continue;
			}
			i++;
		}
		if(j<m){
			cout<<"NO"<<'\n';
			continue;
		}
		cout<<"YES"<<'\n';

		for(auto &x:s){
			if(x=='?'){
				x='a';
			}
		}
		cout<<s<<'\n';
	}
}