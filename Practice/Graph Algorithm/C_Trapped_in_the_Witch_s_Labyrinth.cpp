#include <bits/stdc++.h>
using namespace std;
#define int short
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<string> v;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
map<char, int> mp;
bool dfs(int i, int j) {
    if (!valid(i, j))
        return true;
    if (vis[i][j] == 0)
        return false;
    if (vis[i][j] == 1)
        return true;
    if (vis[i][j] == 2)
        return false;
    vis[i][j] = 2;

    bool flag = true;
    vector<int> ops;
    if (v[i][j] == '?')
        ops = {0, 1, 2, 3};
    else
        ops.push_back(mp[v[i][j]]);
    for (auto vl : ops) {
        auto [x, y] = path[vl];
        x += i, y += j;
        flag &= dfs(x, y);
    }
    return vis[i][j] = flag;
}
void marwan() {
    cin >> n >> m;
    mp['L'] = 0;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    v.assign(n, string());
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vis.assign(n, vector<int>(m, -1));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == -1)
                dfs(i, j);
            if (!vis[i][j])
                ans++;
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}