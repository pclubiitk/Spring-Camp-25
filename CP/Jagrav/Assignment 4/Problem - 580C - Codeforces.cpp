#include<bits/stdc++.h>
#include<climits>
using namespace std;
using ll = long long;
const int mxi = INT_MAX;
const ll mxll = LLONG_MAX;
const int M = 2e5+5;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map 
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define rvrep(i,a,b) for(ll i=n-1; i>=0; i--)
#define sayn cout<<"NO"<<'\n';
#define sayy cout<<"YES"<<'\n';

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

vi a(M); vector<vi> adj(M); int n,m,ans=0;

void dfs(int u, int p, int numC, int maxC){
	if(a[u]){numC++;}
	else{numC=0;}
	maxC=max(maxC,numC);
	int cld=0;
	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u,numC,maxC);
			cld++;
		}
	}
	if(cld==0 && maxC<=m){ans++;}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	
	cin>>n>>m;
	rep(i,1,n){cin>>a[i];}
	rep(i,1,n-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1,0,0);
	cout<<ans;
	return 0;
}