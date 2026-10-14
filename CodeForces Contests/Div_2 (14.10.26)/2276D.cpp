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
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> g;
vector<int> vis, dist;
bool cycle;
void dfs(int u, int p) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (vis[v] && v != p) {
      cycle = true;
    } else if (vis[v] == 0 && v != p) {
      dist[v] = dist[u] + 1;
      dfs(v, u);
    }
  }
}
void marwan(int cs) {
  cin >> n >> m;
  g.assign(n + 1, vector<int>());
  cycle = false;
  vis.assign(n + 1, 0);
  dist.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) {
      cout << "Brain Melt" << endl;
      return;
    }
    if (!vis[i]) {
      dfs(i, 0);
      count++;
    }
  }
  if (cycle || count > 1) {
    cout << "Many" << endl;
    return;
  }
  int a = 1, b = 1;
  for (int i = 1; i <= n; i++) {
    if (dist[a] < dist[i])
      a = i;
  }
  dist.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  dfs(a, 0);
  int mxd = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > 2) {
      cout << "Many" << endl;
      return;
    }
  }
  cout << 2 << endl;
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