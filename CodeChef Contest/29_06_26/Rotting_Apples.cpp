#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), vis(n, vector<int>(m, 0)), dis(n, vector<int>(m, INT_MAX));
    vector<pair<int, int>> rot;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                rot.push_back({i, j});
            }
        }
    }
    queue<pair<int, int>> q;
    for (auto &[x, y] : rot) {
        q.push({x, y});
        vis[x][y] = 1;
        dis[x][y] = 0;
    }
    auto valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    while (!q.empty()) {
        auto &[i, j] = q.front();
        q.pop();
        for (auto [x, y] : path) {
            x += i, y += j;
            // cerr << x << " " << y << endl;
            if (valid(x, y) && vis[x][y] == 0 && v[x][y] != 0) {
                q.push({x, y});
                // cerr << x << " val " << y << endl;
                vis[x][y] = 1;
                dis[x][y] = min(dis[x][y], dis[i][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cerr << dis[i][j] << " ";
            if (dis[i][j] != INT_MAX)
                ans = max(ans, dis[i][j]);
            if (v[i][j] == 1 && dis[i][j] == INT_MAX) {
                minus;
                return;
            }
        }
        // cerr << endl;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}