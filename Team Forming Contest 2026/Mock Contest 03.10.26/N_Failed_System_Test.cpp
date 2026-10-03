#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int tcs, n;
vector<pair<int, int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<char>> v;
vector<vector<bool>> vis;
int tans;
bool valid(int i, int j) { return i >= 1 && j >= 1 && i <= n && j <= n; }
int bfs(int i, int j, char target) {
  //   cerr << i << " " << j << endl;
  //   if (v[i][j] == target) {
  //     // cerr << target << endl;
  //     tans = dist;
  //     return;
  //   }
  //   vis[i][j] = 1;
  //   paths.push_back({i, j});
  //   for (auto [x, y] : path) {
  //     x += i, y += j;
  //     if (valid(x, y) && vis[x][y] == 0 &&
  //         (v[x][y] == '.' || v[x][y] == target)) {
  //       dfs(x, y, target, dist + 1);
  //     }
  //   }
  //   cerr << target << " " << i << " " << j << endl;
  queue<pair<pair<int, int>, int>> q;
  vector<pair<int, int>> paths;
  q.push({{i, j}, 0});
  while (!q.empty()) {
    auto [i1, j1] = q.front().first;
    // cerr << i1 << "HHHHHHH" << j1 << endl;
    int dst = q.front().second;
    vis[i1][j1] = 1;
    paths.push_back({i1, j1});
    if (v[i1][j1] == target) {
      for (auto [u, v] : paths)
        vis[u][v] = false;
      return dst;
    }
    q.pop();
    for (auto [x, y] : path) {
      x += i1, y += j1;
      //   cerr<<x<<" "<<y<<endl;
      if (valid(x, y) && vis[x][y] == 0 &&
          (v[x][y] == '.' || v[x][y] == target)) {
        // cerr<<x<<":"<<y<<endl;
        q.push({{x, y}, dst + 1});
      }
      // cerr << x << " REJECTED " << y << endl;
    }
  }
  for (auto [u, v] : paths)
    vis[u][v] = false;
  return INT_MAX;
  //   vis[i][j] = 0;
}
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  cin >> n;
  v.assign(n + 1, vector<char>(n + 1, '0'));
  vis.assign(n + 1, vector<bool>(n + 1, 0));
  vector<pair<char, pair<int, int>>> t;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      v[i][j] = s[j - 1];
      if (v[i][j] >= 'A' && v[i][j] <= 'Z')
        t.push_back({v[i][j], {i, j}});
    }
  }
  if (t.size() == 1) {
    cout << 0 << endl;
    return;
  }
  sort(all(t));

  int ans = 0;
  for (int idx = 0; idx + 1 < t.size(); idx++) {
    char c = t[idx].first;
    auto [i, j] = t[idx].second;
    char target = t[idx + 1].first;
    tans = bfs(i, j, target);
    if (tans == INT_MAX) {
      cout << "Impossible";
      if (cs != tcs)
        cout << endl;
      return;
    } else {
      v[i][j] = '.';
      ans += tans;
    }
  }
  cout << ans;
  if (cs != tcs)
    cout << endl;
  //   cerr << endl;
  //   cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tcs;
  for (int i = 1; i <= tcs; i++) {
    marwan(i);
  }
  return 0;
}