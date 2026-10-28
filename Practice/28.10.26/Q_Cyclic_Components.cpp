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
vector<int> vis, deg;
int cycle, nd;

void dfs(int u, int p, vector<int> &nds) {
  vis[u] = 1;
  nds.push_back(u);
  for (auto v : g[u]) {
    deg[u]++;
    if (v == p)
      continue;
    if (!vis[v])
      dfs(v, u, nds);
    else if (vis[u]) {
      cycle = 1;
    }
  }
}
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vis.assign(n + 1, 0);
  deg.assign(n + 1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cycle = 0, nd = 0;
    vector<int> nds;
    if (vis[i] == 0) {
      dfs(i, i, nds);
      if (!cycle)
        continue;
      bool flag = true;
      for (auto u : nds) {
        if (deg[u] != 2) {
          flag = false;
          break;
        }
      }
      if (flag)
        ans++;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}