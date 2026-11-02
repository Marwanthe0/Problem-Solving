#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n, m, k;
vector<string> v;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
void dfs(int i, int j) {
    vis[i][j] = 1;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && v[x][y] == '.')
            dfs(x, y);
    }
    if (k > 0)
        v[i][j] = 'X', k--;
}
void marwan() {
    cin >> n >> m >> k;
    v.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (v[i][j] == '.') {
                dfs(i, j);
                flag = false;
                break;
            }
        if (!flag)
            break;
    }
    for (auto s : v)
        cout << s << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}