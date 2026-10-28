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
pair<int, int> dfs(int u, int p, int d) {

  pair<int, int> ans = {0, 0};
  bool flag = 1;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    flag = 0;
    pair<int, int> tans = dfs(v, u, d + 1);
    ans.first += tans.first, ans.second += tans.second;
  }
  if (flag)
    return {1, d};
  return ans;
}
void marwan() {
  cin >> n;
  g.assign(n + 1, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pair<int, int> tans = dfs(1, 1, 0);
  cout << (long double)tans.second / tans.first << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}