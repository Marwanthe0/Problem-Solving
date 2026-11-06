#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<string> g;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    int ssi, ssj, di, dj;
    vector<pair<int, int>> tels;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'P')
                ssi = i, ssj = j;
            if (g[i][j] == 'D')
                di = i, dj = j;
            if (g[i][j] == '*')
                tels.push_back({i, j});
        }
    }
    auto bfs = [&](int si, int sj, bool flag = 0) -> vector<vector<int>> {
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = 1;
        dis[si][sj] = 0;
        int ans = 1e9;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [x, y] : path) {
                x += i, y += j;
                if (valid(x, y) && g[x][y] != '#' && !vis[x][y]) {
                    if (flag && g[x][y] == '*')
                        continue;
                    vis[x][y] = 1;
                    dis[x][y] = dis[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        return dis;
    };
    auto dist1 = bfs(ssi, ssj);
    vis.assign(n, vector<int>(m, 0));
    auto dist2 = bfs(di, dj);
    vis.assign(n, vector<int>(m, 0));
    auto dist3 = bfs(ssi, ssj, 1);
    int ans = dist3[di][dj];
    
    for (auto [i, j] : tels) {
        for (auto [x, y] : tels) {
            if (i == x && j == y)
                continue;
            // cerr << i << " " << j << ", " << x << " " << y << " " << dist1[i][j] << " " << dist2[x][y] << endl;
            ans = min(ans, dist1[i][j] + 1 + dist2[x][y]);
            if (dist1[i][j] >= 1e9 && dist1[x][y] < 1e9 && dist2[x][y] < 1e9)
                ans = min(ans, dist1[x][y] + dist2[x][y] + 2);
        }
    }
    if (ans >= 1e9)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}