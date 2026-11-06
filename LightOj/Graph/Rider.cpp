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
vector<vector<int>> vis, cnt, dist, dist2;
bool valid(int i, int j) {return i >= 0 && j >= 0 && i < n && j < m;}
vector<int> path = {2, 1, -2, -1};
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    vis.assign(n, vector<int>(m, 0));
    cnt.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, 0));
    dist2.assign(n, vector<int>(m, 0));
    vector<tuple<int, int, int>> knights;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '.')
                knights.push_back({i, j, g[i][j] - '0'});
        }
    }
    for (auto [si, sj, jump] : knights) {
        vis.assign(n, vector<int>(m, 0));
        dist.assign(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = 1;
        dist[si][sj] = 0;
        cnt[si][sj]++;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto tx : path) {
                for (auto ty : path) {
                    if (abs(tx) == abs(ty))
                        continue;
                    int x = tx, y = ty;
                    x += i, y += j;
                    if (valid(x, y) && !vis[x][y]) {
                        q.push({x, y});
                        vis[x][y] = 1;
                        cnt[x][y]++;
                        dist[x][y] = min(dist[i][j] + 1, dist[x][y]);
                        dist2[x][y] += ((dist[x][y] / jump) + (dist[x][y] % jump != 0));
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cerr << dist2[i][j] << " ";
            if (cnt[i][j] >= knights.size()) {
                ans = min(ans, dist2[i][j]);
            }
        }
        // cerr << endl;
    }
    // cerr << endl;
    if (ans >= 1e9)
        minus;
    else
        cout << ans << endl;
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