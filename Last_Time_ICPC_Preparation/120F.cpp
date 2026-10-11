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
void dfs(int nd, int dst, vector<vector<int>> &g, vector<int> &dist,
         vector<int> &vis) {
  vis[nd] = 1;
  dist[nd] = dst;
  for (auto child : g[nd]) {
    if (!vis[child])
      dfs(child, dst + 1, g, dist, vis);
  }
}
int f() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>());
  int k = 2 * (n - 1);
  vector<int> tmp(k);
  for (int i = 0; i < k; i++) {
    cin >> tmp[i];
  }
  for (int i = 0; i < k; i += 2) {
    g[tmp[i]].push_back(tmp[i + 1]);
    g[tmp[i + 1]].push_back(tmp[i]);
  }
  vector<int> dist(n + 1, 0), vis(n + 1, 0);
  dfs(1, 0, g, dist, vis);
  int mx = 0, a = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > mx)
      mx = dist[i], a = i;
    // cerr << i << " " << dist[i] << endl;
  }
  //   cerr << "a " << a << endl;
  vis.assign(n + 1, 0);
  dist.assign(n + 1, 0);
  dfs(a, 0, g, dist, vis);
  mx = 0;
  int b;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > mx)
      mx = dist[i], b = i;
    // cerr << i << " " << dist[i] << endl;
  }
  //   cerr << "B " << b << endl;
  return mx;
}
void marwan() {
  int n;
  cin >> n;
  int ans = 0ll;
  for (int i = 0; i < n; i++) {
    ans += f();
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  marwan();
  return 0;
}