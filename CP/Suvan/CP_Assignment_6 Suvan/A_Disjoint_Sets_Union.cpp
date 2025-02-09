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
vi Size;
void make(int n){
    parent[n] = n;
    Size[n] = 1;
}
int find(int n){
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(Size[a]<Size[b]){
        swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
    
}
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;
        parent.resize(n);
        Size.resize(n);
        for(int i = 0; i<n; i++){
            make(i);
        }
        for(int i = 0; i<q; i++){
            string s;
            int n,m;
            cin>>s>>n>>m;
            if(s[0] =='u'){
                Union(n-1,m-1);
            }
            if(s[0] == 'g'){
                if(find(n-1) == find(m-1)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}