#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (auto &row : v) {
        for (auto &vl : row)
            cin >> vl;
    }
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int j = 0; j < m; j++) {
        int val = 0ll;
        for (int i = 0; i < n; i++) {
            val |= v[i][j];
            v[i][j] = val;
            ans[j][i] = val;
        }
    }
    // for (auto &row : v) {
    //     for (auto &vl : row) {
    //         cout << vl << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto &row : ans) {
    //     for (auto &vl : row) {
    //         cout << vl << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    while (q--) {
        int k;
        cin >> k;
        map<int, pair<int, int>> op;
        for (int i = 0; i < k; i++) {
            int a, c;
            char b;
            cin >> a >> b >> c;
            a--;
            if (!op.count(a)) {
                if (b == '>') {
                    op[a] = {c, INT_MAX};
                } else
                    op[a] = {INT_MIN, c};
            } else {
                if (b == '>') {
                    op[a].first = max(op[a].first, c);
                } else
                    op[a].second = min(op[a].second, c);
            }
        }
        int l = 0ll, r = n - 1;
        bool flag = true;
        for (auto &[x, y] : op) {
            auto &[i, j] = y;
            // cerr << x << " " << i << " " << j << endl;
            if ((i > j) || (x < 0) || (x >= m)) {
                cout << -1 << endl;
                flag = false;
                break;
            }
            int newl = (upper_bound(all(ans[x]), i) - ans[x].begin());
            if (newl > r) {
                cout << -1 << endl;
                flag = false;
                break;
            }
            l = max(l, newl);
            int newr = (lower_bound(all(ans[x]), j) - ans[x].begin());
            newr--;
            if (newr < l) {
                cout << -1 << endl;
                flag = false;
                break;
            }
            r = min(r, newr);
        }
        if (flag)
            cout << l + 1 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}