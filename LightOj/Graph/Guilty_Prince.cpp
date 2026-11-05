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
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
int dfs(int i, int j) {
    vis[i][j] = 1;
    int ans = 1;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && g[x][y] != '#')
            ans += dfs(x, y);
    }
    return ans;
}
void marwan(int cs) {
    cin >> m >> n;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    int si, sj;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '@')
                si = i, sj = j;
        }
    }
    cout << dfs(si, sj) << endl;
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