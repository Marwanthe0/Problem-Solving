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
int n;
vector<vector<int>> g;
vector<int> vis;
int nds;
int ans;
void sdfs(int u, int p) {
  nds++;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    sdfs(v, u);
  }
}

int dfs(int u, int p) {
  int child = 1;
  vis[u] = 1;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    if (!vis[v])
      child += dfs(v, u);
  }

  int upper = nds - child;
  if (upper % 2 == 0 && child % 2 == 0 && upper && child) {
    ans++;
  }
  return child;
}
void marwan() {
  cin >> n;
  g.assign(n + 1, vector<int>());
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vis.assign(n + 1, 0);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    nds = 0;
    if (!vis[i]) {
      sdfs(i, i);
      if (nds & 1) {
        minus;
        return;
      }
      dfs(i, i);
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