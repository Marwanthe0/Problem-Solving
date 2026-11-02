#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
map<char, int> tag;
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
bool dfs(int i, int j, int l, int r, int dist) {
    if (vis[i][j] != -1)
        return vis[i][j];
    if (g[i][j] == '?')
        return vis[i][j] = dist > 0;
    auto [x, y] = path[tag[g[i][j]]];
    x += i, y += j;
    if (!valid(x, y))
        return vis[i][j] = false;
    else if (x == l && y == r)
        return vis[i][j] = 1;
    return vis[i][j] = dfs(x, y, i, j, dist + 1);
}
bool dfs2(int i, int j, int dist) {
    if (vis[i][j] == 1)
        return true;
    bool ans = false;
    if (g[i][j] == '?' && dist > 0)
        return vis[i][j] = true;
    else if (dist > 0)
        return false;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y)) {
            ans |= dfs2(x, y, dist + 1);
            if (ans)
                break;
        }
    }
    return vis[i][j] = ans;
}
void marwan(int cs) {
    tag['R'] = 0;
    tag['L'] = 1;
    tag['U'] = 2;
    tag['D'] = 3;
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == -1 && g[i][j] != '?')
                bool x = dfs(i, j, -1, -1, 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '?') {
                dfs2(i, j, 0);
            }
            ans += vis[i][j];
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}