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
int n, k;
vector<vector<int>> g;
vector<int> level, nal, par, vis;
int ans;
int count = 0;
void dfs1(int nd, int p) {
  for (auto child : g[nd]) {
    if (child != p) {
      par[child] = nd;
      dfs1(child, nd);
    }
  }
}
int dfs(int nd, int d, vector<int> nds) {
  if (d >= k)
    return 1;
  vis[nd] = 1;
  nds.push_back(nd);
  int tans = 0ll;
  for (auto child : g[nd]) {
    if (!vis[child])
      tans += dfs(child, d + 1, nds);
  }
  return tans;
}
void marwan() {
  cin >> n >> k;
  g.assign(n + 1, vector<int>());
  level.assign(n + 1, 0);
  nal.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  par.assign(n + 1, -1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, -1);
  ans = 0ll;

  for (int i = 1; i <= n; i++) {
    vector<int> nds;
    ans += dfs(i, 0, nds);
    cerr << i << " " << ans << endl;
    for (auto vl : nds)
      vis[vl] = 0;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}