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
vector<vector<int>> vis, dist;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, 0));
    vector<pair<int, int>> targets;
    pair<int, int> src;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'a' || g[i][j] == 'b' || g[i][j] == 'c')
                targets.push_back({i, j});
            if (g[i][j] == 'h') {
                src = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({src.first, src.second});
    vis[src.first][src.second] = 1;
    dist[src.first][src.second] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y] : path) {
            x += i, y += j;
            if (valid(x, y) && !vis[x][y] && g[x][y] != 'm' && g[x][y] != '#') {
                q.push({x, y});
                vis[x][y] = 1;
                dist[x][y] = dist[i][j] + 1;
            }
        }
    }
    int ans = 0;
    for (auto [i, j] : targets) {
        ans = max(ans, dist[i][j]);
    }
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