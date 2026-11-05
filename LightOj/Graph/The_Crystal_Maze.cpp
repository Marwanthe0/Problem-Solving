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
int n, m, q;
vector<string> g;
vector<vector<int>> vis, cnt;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
int dfs(int i, int j) {
    vis[i][j] = 1;
    int tans = g[i][j] == 'C';
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && g[x][y] != '#')
            tans += dfs(x, y);
    }
    return tans;
}
void dfs2(int i, int j, int val) {
    cnt[i][j] = val;
    vis[i][j] = 1;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && g[x][y] != '#')
            dfs2(x, y, val);
    }
}
void marwan(int cs) {
    cin >> n >> m >> q;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    cnt.assign(n, vector<int>(m, 0));
    vector<tuple<int, int, int>> crystals;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                int tans = dfs(i, j);
                crystals.push_back({i, j, tans});
            }
        }
    }
    vis.assign(n, vector<int>(m, 0));
    for (auto [i, j, val] : crystals) {
        dfs2(i, j, val);
    }
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        cout << cnt[i][j] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}