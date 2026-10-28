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
vector<set<int>> g;
vector<int> vis, nds;
pair<int, int> dfs(int u, int p) {
  vis[u] = 1;
  pair<int, int> ans = {1, 0};
  for (auto v : g[u]) {
    ans.second++;
    if (!vis[v]) {
      pair<int, int> tans = dfs(v, u);
      ans.first += tans.first, ans.second += tans.second;
    }
  }
  return ans;
}
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, set<int>());
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      pair<int, int> tans = dfs(i, i);
      if (tans.first * (tans.first - 1) != tans.second) {
        no;
        return;
      }
    }
  }
  yes;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}