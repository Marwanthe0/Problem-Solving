#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 200000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    vector<int> fr(n + 10, 0ll);
    for (auto &vl : t) {
        cin >> vl;
        fr[vl]++;
    }
    vector<int> sum(3, 0ll);
    int mex;
    for (int j = 0; j < 3; j++) {
        mex = 0;
        while (fr[mex] > 0)
            mex++;
        vector<int> nf(n + 10, 0);
        for (int i = 0; i < n; i++) {
            if (t[i] < mex) {
                if (fr[t[i]] != 1) {
                    t[i] = mex;
                }
            } else if (t[i] > mex) {
                t[i] = mex;
            }
            nf[t[i]]++;
            sum[j] += t[i];
        }
        fr = nf;
    }
    if (k == 1)
        cout << sum[0] << endl;
    else if (k % 2 == 0)
        cout << sum[1] << endl;
    else
        cout << sum[2] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}