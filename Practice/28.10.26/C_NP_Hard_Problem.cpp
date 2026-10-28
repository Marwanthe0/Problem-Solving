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
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> g;
vector<int> a, b, vis;
bool dfs(int u, int p, int color) {
  vis[u] = color;
  bool ans = true;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    if (vis[v] != -1) {
      if (vis[v] == color)
        return false;
    } else
      ans &= dfs(v, u, !color);
  }
  return ans;
}
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<int>());
  vis.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == -1) {
      if (!dfs(i, i, i & 1)) {
        minus;
        return;
      }
    }
    if (vis[i])
      a.push_back(i);
    else
      b.push_back(i);
  }
  cout << a.size() << endl;
  for (auto vl : a)
    cout << vl << " ";
  cout << endl;
  cout << b.size() << endl;
  for (auto vl : b)
    cout << vl << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}