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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (auto &val : v) {
        for (auto &vl : val)
            cin >> vl;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int x = v[i][j], y = v[i][j + 1], z = v[i + 1][j], w = v[i + 1][j + 1];
            if (x == y && y == z && z == w)
                ans = max(ans, x);
        }
    }
    cout << ans << endl;
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