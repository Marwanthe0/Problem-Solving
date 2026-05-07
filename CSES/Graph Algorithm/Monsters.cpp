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
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void clear(vector<vector<int>> &vis) {
    int n = vis.size(), m = vis[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;
    }
}
string pth = "DULR";
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<pair<int, int>> monsters;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'M')
                monsters.push_back({i, j});
            else if (v[i][j] == 'A')
                start = {i, j};
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0)), dist(n, vector<int>(m, 1e7)), dist2(n, vector<int>(m, 1e7));
    queue<pair<int, int>> q;
    for (auto [x, y] : monsters) {
        vis[x][y] = 1;
        dist[x][y] = 0;
        q.push({x, y});
    }
    auto valid = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y] : path) {
            x += i, y += j;
            if (valid(x, y) && !vis[x][y] && v[x][y] != '#') {
                vis[x][y] = 1;
                q.push({x, y});
                dist[x][y] = min(dist[x][y], dist[i][j] + 1);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (dist[i][j] != 1e7) {
    //             cerr << dist[i][j] << " ";
    //         } else {
    //             cerr << -1 << " ";
    //         }
    //     }
    //     cerr << endl;
    // }
    clear(vis);
    q.push(start);
    vis[start.first][start.second] = 1;
    dist2[start.first][start.second] = 0;
    bool flag = false;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            yes;
            string anspath = "";
            // cerr << i << " " << j << endl;
            while (1) {
                if (i == start.first && j == start.second) {
                    break;
                }
                int mn = INT_MAX, ti, tj, count = 0, tcount;
                for (auto [x, y] : path) {
                    x += i, y += j;
                    if (valid(x, y) && v[x][y] != '#' && dist2[x][y] < mn) {
                        mn = dist2[x][y];
                        ti = x, tj = y;
                        tcount = count;
                    }
                    count++;
                }
                i = ti, j = tj;
                // cerr << i << " " << j << endl;
                anspath.push_back(pth[tcount]);
            }
            reverse(all(anspath));
            cout << anspath.size() << endl;
            cout << anspath << endl;
            return;
        }
        for (auto [x, y] : path) {
            x += i, y += j;
            if (valid(x, y) && !vis[x][y] && v[x][y] != '#' && dist[x][y] > (dist2[i][j] + 1)) {
                vis[x][y] = 1;
                q.push({x, y});
                dist2[x][y] = min(dist2[x][y], dist2[i][j] + 1);
            }
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}