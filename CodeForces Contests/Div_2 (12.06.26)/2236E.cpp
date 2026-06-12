#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n), t;
    for (auto &vl : v)
        cin >> vl;
    t = v;
    reverse(all(t));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
    // for (int i = 0; i < n; i++) {
    //     int xx = v[i], yy = v[i];
    //     for (int j = i; j >= 0; j--) {
    //         xx = min(xx, v[j]);
    //         yy = max(yy, v[j]);
    //         mn[i][j] = xx, mx[i][j] = yy;
    //     }
    // }
    int sz = n;
    if (sz & 1)
        sz--;
    for (int i = n / 2; i > 0; i--) {
        int l = 0, r = 0;
        map<int, int> m;
        while (r < n) {
            m[v[r]]++;
            if (r - l + 1 == i) {
                // cerr << r << " " << l << endl;
                int mni = m.begin()->first;
                int mxi = m.rbegin()->first;
                if (m.size() == i && mxi - mni + 1 == i) {
                    ans[i][mni] = 1;
                }
                m[v[l]]--;
                if (m[v[l]] <= 0) {
                    m.erase(v[l]);
                }
                l++;
            }
            r++;
        }
    }
    for (int i = n / 2; i > 0; i--) {
        for (int j = 1; j + i <= n; j++) {
            if (ans[i][j] && ans[i][j + i]) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
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