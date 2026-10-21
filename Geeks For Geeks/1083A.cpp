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
vector<vector<pair<int, int>>> g;
int n;
vector<int> a, cost;
int dfs(int u, int p) {

  vector<int> cst;
  for (auto [v, c] : g[u]) {
    if (v != p) {
      int x = dfs(v, u);
      if (x >= c)
        cst.push_back(x - c);
    }
  }
  int sum = a[u];
  if (cst.empty())
    return cost[u] = sum;
  if (cst.size() == 1)
    return cost[u] = sum + cst[0];
  sort(all(cst));
  reverse(all(cst));
  sum += cst[0] + cst[1];
  cost[u] = sum;
  return a[u] + cst[0];
}
void marwan() {
  cin >> n;
  a.assign(n + 1, 0);
  cost.assign(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  g.assign(n + 1, vector<pair<int, int>>());
  for (int i = 0; i + 1 < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  dfs(1, -1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, cost[i]);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}