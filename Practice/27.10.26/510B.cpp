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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, m;
vector<string> v;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
int dfs(int i, int j, int pi, int pj) {
  vis[i][j] = 1;
  for (auto [x, y] : path) {
    x += i, y += j;
    if (x == pi && y == pj)
      continue;
    if (valid(x, y) && v[x][y] == v[i][j]) {
      if (vis[x][y])
        return true;
      else if (dfs(x, y, i, j))
        return true;
    }
  }
  return false;
}
void marwan() {
  cin >> n >> m;
  v.assign(n, string());
  vis.assign(n, vector<int>(m, 0));
  for (auto &s : v)
    cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        if (dfs(i, j, i, j)) {
          yes;
          return;
        }
      }
    }
  }
  no;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}