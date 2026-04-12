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
class point {
  public:
    int i, j, dir, streak;
    point(int i, int j, int dir, int streak) {
        this->i = i;
        this->j = j;
        this->dir = dir;
        this->streak = streak;
    }
};
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }
bool dfs(int i, int j, vector<string> &v, vector<vector<int>> &vis) {
    if (v[i][j] == 'T')
        return true;
    vis[i][j] = 1;
    bool ans = false;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y, v.size(), v[0].size()) && !vis[x][y] && v[x][y] != '#') {
            ans |= dfs(x, y, v, vis);
        }
    }
    return ans;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> s, t;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'S')
                s = {i, j};
            if (v[i][j] == 'T')
                t = {i, j};
        }
    }
    point start(s.first, s.second, 0, 0);
    int vis[n][m][5][4], level[n][m][5][4];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 5; d++)
                for (int s = 0; s < 4; s++)
                    level[i][j][d][s] = INT_MAX, vis[i][j][d][s] = 0;
    level[start.i][start.j][0][0] = 0;
    vis[start.i][start.j][0][0] = 1;
    queue<point> q;
    q.push(start);
    while (!q.empty()) {
        point nd = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            auto [x, y] = path[k];
            x += nd.i, y += nd.j;
            int dir, streak;
            if (k + 1 == nd.dir)
                dir = k + 1, streak = nd.streak + 1;
            else
                dir = k + 1, streak = 1;
            if (valid(x, y, n, m) && streak < 4 && !vis[x][y][dir][streak] && v[x][y] != '#') {
                point temp(x, y, dir, streak);
                q.push(temp);
                vis[x][y][dir][streak] = 1;
                level[x][y][dir][streak] = min(level[x][y][dir][streak], level[nd.i][nd.j][nd.dir][nd.streak] + 1);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ans = min(ans, level[t.first][t.second][i][j]);
        }
    }
    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}