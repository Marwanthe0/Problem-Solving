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
int n, m;
vector<string> v;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
pair<int, int> dfs(int i, int j) {
    vis[i][j] = 1;
    pair<int, int> ans = {0, 0};
    if (v[i][j] == 'k')
        ans.first++;
    else if (v[i][j] == 'v')
        ans.second++;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && v[x][y] != '#') {
            pair<int, int> tans = dfs(x, y);
            ans.first += tans.first;
            ans.second += tans.second;
        }
    }
    return ans;
}
void marwan() {
    cin >> n >> m;
    v.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && v[i][j] != '#') {
                pair<int, int> tans = dfs(i, j);
                if (tans.first > tans.second)
                    ans.first += tans.first;
                else
                    ans.second += tans.second;
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}