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
int n, k;
vector<int> a;
vector<vector<int>> g;
int dfs(int u, int p, int cnt) {

  int ans = 0, flag = true;
  if (a[u])
    cnt++;
  else
    cnt = 0;
  if (cnt > k)
    return 0;
  for (auto v : g[u]) {
    if (v != p) {
      flag = false;
      ans += dfs(v, u, cnt);
    }
  }
  if (flag)
    return 1;
  else
    return ans;
}
void marwan() {
  cin >> n >> k;
  g.assign(n + 1, vector<int>());
  a.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << dfs(1, 1, 0) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}