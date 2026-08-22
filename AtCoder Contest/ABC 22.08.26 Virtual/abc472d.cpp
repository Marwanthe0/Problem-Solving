#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  vector<vector<int>> vis(n, vector<int>(m, 0)),
      dist(n, vector<int>(m, INT_MAX));
  vector<int> tt(n, 0), ttt(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      tt[i] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (v[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if (flag)
      ttt[j] = 1;
  }
  //   for (auto vl : tt)
  //     cerr << vl << " ";
  //   cerr << endl;
  //   for (auto vl : ttt)
  //     cerr << vl << " ";
  //   cerr << endl;
  //   return;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tt[i] && ttt[j]) {
        q.push({i, j});
        cerr << i << " " << j << endl;
        vis[i][j] = 1;
        dist[i][j] = 0;
      }
    }
  }
  //   return;
  vector<pair<int, int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  auto valid = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; };
  while (!q.empty()) {
    auto pp = q.front();
    int x = pp.first, y = pp.second;
    q.pop();
    for (auto ps : path) {
      int i = ps.first, j = ps.second;
      i += x, j += y;
      if (valid(i, j) && v[i][j] == '.' && vis[i][j] == 0) {
        q.push({i, j});
        vis[i][j] = 1;
        dist[i][j] = dist[x][y] + 1;
      }
    }
  }
  int ans = 0ll;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      //   cerr << dist[i][j] << " ";
      if (v[i][j] == '.' && dist[i][j] <= k)
        ans++;
    }
    // cerr << endl;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  marwan();
  return 0;
}