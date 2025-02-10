#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define vpll vector<pair<ld, ld>>
#define vdll vector<vector<ld>>
#define pll pair<ld, ld>
#define vll vector<ld>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()

vdll matrixmul(vdll m, vdll n)
{
    int sz = m.size();
    vdll res(sz, vll(sz, 0.0)); 
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            for (int k = 0; k < sz; k++)
            {
                res[i][j] += m[i][k] * n[k][j]; 
            }
        }
    }
    return res;
}

vdll matrixexp(vdll m, long long pw)
{
    int sz = m.size();
    vdll res(sz, vll(sz, 1.0));

    while (pw)
    {
        if (pw & 1) res = matrixmul(res, m);
        m = matrixmul(m, m);
        pw >>= 1;
    }
    return res;
}

int main()
{
    long long n;
    ld p;
    cin >> n >> p;

    vdll b = {{1 - p, p}, {p, 1 - p}};
    vdll e= {{1-p},{p}};
    vdll res = matrixexp(b, n-1);
    vdll g = matrixmul(res,e);

    cout << fixed << setprecision(10) << g[0][0] << endl;

    return 0;
}
