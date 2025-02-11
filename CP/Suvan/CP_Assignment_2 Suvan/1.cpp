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

int main() {
    fast_io();

    double a;
    cin >> a;

    double l = 0, r = a;  
    for (int i = 0; i < 1000; i++) {
        double mid = (r + l) / 2;
        double tar = mid * mid + sqrt(mid);

        if (abs(tar - a) < 1e-9) {  
            cout << fixed << setprecision(12) << mid << endl;
            break;
        } 
        else if (tar < a) {
            l = mid;  
        } 
        else {
            r = mid; 
        }
    }

    return 0;
}