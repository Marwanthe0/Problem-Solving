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
vector<int> vis;
int dfs(int nd) {
  vis[nd] = 1;
  int count = 1;
  for (auto child : g[nd]) {
    if (!vis[child])
      count += dfs(child);
  }
  return count;
}
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vis.assign(n + 1, 0);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      ans.push_back(dfs(i));
  }
  sort(all(ans));
  reverse(all(ans));
  int uttor = 1ll;
  for (auto vl : ans) {
    cerr << vl << " ";
    uttor = uttor * 1ll * (1ll << (vl - 1));
  }
  cout << uttor << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}