#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define ns 30
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
int n;
vector<vector<pair<int, int>>> g;
vector<vector<int>> up;
vector<int> dif, level, uttor;
void dfs(int u, int p) {
  up[0][u] = p;
  for (auto [v, idx] : g[u]) {
    if (v != p) {
      level[v] = level[u] + 1;
      dfs(v, u);
    }
  }
}
int lca(int u, int v) {
  if (level[u] < level[v]) {
    swap(u, v);
  }
  int d = level[u] - level[v];
  for (int k = 0; k < ns; k++) {
    if (d & (1 << k)) {
      u = up[k][u];
    }
  }
  if (u == v)
    return v;
  for (int k = ns - 1; k >= 0; k--) {
    if (up[k][u] != up[k][v]) {
      u = up[k][u];
      v = up[k][v];
    }
  }
  return up[0][u];
}
int dfs2(int u, int p) {

  int ans = dif[u];
  for (auto [v, idx] : g[u]) {
    if (v != p) {
      int tans = dfs2(v, u);
      uttor[idx] = tans;
      ans += tans;
    }
  }
  return dif[u] = ans;
}
void marwan() {
  cin >> n;
  g.assign(n + 1, vector<pair<int, int>>());
  up.assign(ns, vector<int>(n + 1, 0));
  dif.assign(n + 1, 0);
  level.assign(n + 1, 0);
  uttor.assign(n, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }

  dfs(1, 0);

  for (int k = 1; k < ns; k++) {
    for (int u = 1; u <= n; u++) {
      up[k][u] = up[k - 1][up[k - 1][u]];
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int c = lca(a, b);
    dif[a]++, dif[b]++, dif[c] -= 2;
  }
  dfs2(1, 0);
  for (int i = 1; i < n; i++)
    cout << uttor[i] << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}