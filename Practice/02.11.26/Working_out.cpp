#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> v, dp1, dp2, dp3, dp4;
void marwan() {
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    dp1.assign(n, vector<int>(m, 0));
    dp2.assign(n, vector<int>(m, 0));
    dp3.assign(n, vector<int>(m, 0));
    dp4.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    // 00 -> n - 1,m - 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp1[i][j] = v[i][j];
            dp1[i][j] += max((i ? dp1[i - 1][j] : 0), (j ? dp1[i][j - 1] : 0));
        }
    }
    // n - 1, m - 1 -> 00
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp2[i][j] = v[i][j];
            dp2[i][j] += max((i != n - 1 ? dp2[i + 1][j] : 0), (j != m - 1 ? dp2[i][j + 1] : 0));
        }
    }
    // n - 1,0 -> 0,m - 1
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dp3[i][j] = v[i][j];
            dp3[i][j] += max((i != n - 1 ? dp3[i + 1][j] : 0), (j ? dp3[i][j - 1] : 0));
        }
    }
    // 0,m - 1 ->n - 1,0
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            dp4[i][j] = v[i][j];
            dp4[i][j] += max((i ? dp4[i - 1][j] : 0), (j != m - 1 ? dp4[i][j + 1] : 0));
        }
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            int x = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
            int y = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
            ans = max({ans, x, y});
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}