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
void dfs(int i, int j, char cur) {
    vis[i][j] = 1;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && g[x][y] != cur)
            dfs(x, y, cur);
    }
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    map<char, int> done;
    for (char c = 'A'; c <= 'Z'; c++) {
        vis.assign(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && g[0][j] != c)
                dfs(0, j, c);
            if (!vis[n - 1][j] && g[n - 1][j] != c)
                dfs(n - 1, j, c);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && g[i][0] != c)
                dfs(i, 0, c);
            if (!vis[i][m - 1] && g[i][m - 1] != c)
                dfs(i, m - 1, c);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j])
                    g[i][j] = c;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}