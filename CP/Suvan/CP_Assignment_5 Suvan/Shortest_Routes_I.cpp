#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
typedef pair<int, int> pii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n;
vector<vector<pii> > adj; 
vector<long long > dis; 
set<pair<long long,int> > st;

void Dijkstra(int source) {
   dis[source] = 0;
   st.insert(make_pair(0,source));

   while(!st.empty()){
    auto top = *st.begin();
    st.erase(st.begin());
    long long wt = top.first;
    int city = top.second;

    if(wt > dis[city]) continue;

    for(auto& it : adj[city]){
        long long wt1 = it.second;
        int child = it.first;
        if(wt + wt1 < dis[child]){
            if (dis[child] != LLONG_MAX) {
                st.erase(make_pair(dis[child], child));
            }
            dis[child] = wt + wt1;
            st.insert(make_pair(dis[child],child));
        }
        
    }
   }
}

int main() {
    fast_io();
    int test = 1;
    // cin>>test;
    while(test--){
    int m;
    cin >> n >> m;
    
    adj.assign(n + 1, vector<pii>());
    dis.assign(n + 1, LLONG_MAX); 

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    
    Dijkstra(1);
    
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    }
    return 0;
}
 