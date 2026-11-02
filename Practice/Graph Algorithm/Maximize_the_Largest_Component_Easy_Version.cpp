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
vector<string> v;
vector<vector<int>> vis, color;

vector<int> comps;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }

int dfs(int i, int j, int idx) {
    vis[i][j] = 1;
    color[i][j] = idx;
    int ans = 1;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && !vis[x][y] && v[x][y] == '#')
            ans += dfs(x, y, idx);
    }
    return ans;
}
void marwan(int cs) {
    cin >> n >> m;
    comps.clear();
    v.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    color.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    comps.push_back(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && v[i][j] == '#') {
                int sz = dfs(i, j, comps.size());
                comps.push_back(sz);
            }
            // cout << color[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            count += v[i][j] == '.';
        }
        set<int> idxs;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') {
                idxs.insert(color[i][j]);
            }
            if (i && color[i - 1][j])
                idxs.insert(color[i - 1][j]);
            if (i + 1 < n && color[i + 1][j])
                idxs.insert(color[i + 1][j]);
        }
        int tans = count;
        for (auto idx : idxs)
            tans += comps[idx];
        ans = max(ans, tans);
        // cerr << tans << " ";
    }
    // cerr << endl;
    for (int j = 0; j < m; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += v[i][j] == '.';
        }
        set<int> idxs;
        for (int i = 0; i < n; i++) {
            if (v[i][j] == '#') {
                idxs.insert(color[i][j]);
            }
            if (j && color[i][j - 1])
                idxs.insert(color[i][j - 1]);
            if (j + 1 < m && color[i][j + 1])
                idxs.insert(color[i][j + 1]);
        }
        int tans = count;
        for (auto idx : idxs)
            tans += comps[idx];
        ans = max(ans, tans);
        // cerr << tans << " ";
    }
    cout << ans << endl;
    // cerr << endl;
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