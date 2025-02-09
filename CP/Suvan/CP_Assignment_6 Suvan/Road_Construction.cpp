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
int number_of_sets;
int max_set;
void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    else return parent[v] = find(parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
        number_of_sets--;
        max_set = max(max_set,Size[a]);
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

        number_of_sets = n;
        max_set = 1;

        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            a--,b--;
            Union(a,b);
            cout<<number_of_sets<<" "<<max_set<<endl;   
        }
    }

    return 0;
}