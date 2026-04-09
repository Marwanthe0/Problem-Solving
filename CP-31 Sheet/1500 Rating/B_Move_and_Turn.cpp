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
int dp[1001][30][30][2];
vector<vector<int>> vis(1001, vector<int>(1001, 0));
int f(int i, int x, int y, bool h) {
    if (i == 0) {
        return 1;
    }
    vis[x][y] = 1;
    if (dp[i][x][y][h] != -1)
        return dp[i][x][y][h];
    int ans = 0;
    if (h) {
        if (!vis[x + 1][y])
            ans += f(i - 1, x + 1, y, !h);
        if (!vis[x - 1][y])
            ans += f(i - 1, x - 1, y, !h);
    } else {
        if (!vis[x][y + 1])
            ans += f(i - 1, x, y + 1, !h);
        if (y > 0 && !vis[x][y - 1])
            ans += f(i - 1, x, y - 1, !h);
    }
    return dp[i][x][y][h] = ans;
}
void marwan() {
    vector<pair<int, int>> base = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n;
    cin >> n;
    bool flag = true;
    int ans = 0;
    for (auto [x, y] : base) {
        ans += f(n - 1, x, y, flag);
        flag = !flag;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 30; j++) {
            for (int k = 0; k < 30; k++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    marwan();
    return 0;
}