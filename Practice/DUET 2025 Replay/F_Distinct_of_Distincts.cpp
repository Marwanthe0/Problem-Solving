#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n, m;
    cin >> n >> m;
    if (n <= m) {
        cout << min(max(n, m), 2 * min(n, m)) << endl;
        for (int i = 1, k = m; i <= n; i++, k--) {
            int x = 1;
            for (int j = 1; j <= m; j++) {
                cout << x << " ";
                if (j < k)
                    x++;
            }
            cout << endl;
        }
    } else {
        swap(n, m);
        cout << min(max(n, m), 2 * min(n, m)) << endl;
        vector<vector<int>> ans;
        for (int i = 1, k = m; i <= n; i++, k--) {
            int x = 1;
            vector<int> t;
            for (int j = 1; j <= m; j++) {
                // cout << x << " ";
                t.push_back(x);
                if (j < k)
                    x++;
            }
            ans.push_back(t);
            // cout << endl;
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        // for (auto vl : ans) {
        //     for (auto val : vl)
        //         cout << val << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }
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