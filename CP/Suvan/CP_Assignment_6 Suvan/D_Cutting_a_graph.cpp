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
vi parent;
vi p_parent;
vi s;
void make(int n){
    parent[n] = n;
    p_parent[n] = n;
    s[n] = 1;
}
int find(int n){
    if(parent[n]==n) return n;
    else return parent[n] = find(parent[n]);
}
void Union(int a, int b){
    int c = b;
    a = find(a);
    b = find(b);
    if(a!=b){
        if(s[a]<s[b]) swap(a,b);
        parent[b] = a;
        p_parent[c] = b;
        s[a] += s[b];
    }
}
void cut(int a, int b){
    a = find(a);
    b = find(b);
    p_parent[a];
}
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,m,q;
        cin>>n>>m>>q;
        parent.resize(n);
        s.resize(n);
        for(int i = 0; i<n; i++){
            make(i);
        }
        for(int i = 0; i<m; i++){
            int a,b;
            cin>>a>>b;
            a--,b--;
            Union(a,b);
        }
        for(int i = 0; i<q; i++){
            string s;
            int a, b;
            cin>>s>>a>>b;
            if(s[0]=='a'){
                if(find(a)==find(b)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{

            }
        }
    }

    return 0;
}


