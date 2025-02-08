#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solve(int n, vector<vector<int> >& a) {
    vector<long long> sum(n, 0);
    set<long long> mex_set;

    // Calculate the sum for each queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i] += a[i][j];
        }
        mex_set.insert(sum[i]);
    }

    int mex = 0;
    for (int i = 0; i < n; i++) {
        // Find the maximum sum that can be reduced to i
        auto it = mex_set.lower_bound(i);
        if (it == mex_set.end()) break;
        
        long long val = *it;
        mex_set.erase(it);
        mex_set.insert(i);
        
        // Update mex
        while (mex_set.count(mex)) mex++;
    }

    return mex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        cout << solve(n, a) << "\n";
    }

    return 0;
}
