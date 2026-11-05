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
vector<vector<int>> vis, dist, dist2;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, 1e9));
    dist2.assign(n, vector<int>(m, 1e9));
    vector<pair<int, int>> fires;
    int si, sj;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'F') {
                q.push({i, j});
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
            if (g[i][j] == 'J')
                si = i, sj = j;
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y] : path) {
            x += i, y += j;
            if (valid(x, y) && !vis[x][y] && g[x][y] != '#') {
                vis[x][y] = 1;
                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    vis.assign(n, vector<int>(m, 0));
    dist2[si][sj] = 0;
    vis[si][sj] = 1;
    q.push({si, sj});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y] : path) {
            x += i, y += j;
            if (!valid(x, y)) {
                cout << dist2[i][j] + 1 << endl;
                return;
            }
            if (valid(x, y) && !vis[x][y] && g[x][y] != '#' && dist[x][y] > dist2[i][j] + 1) {
                dist2[x][y] = dist2[i][j] + 1;
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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