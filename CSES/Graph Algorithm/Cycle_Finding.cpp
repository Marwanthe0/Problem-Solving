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
vector<vector<pair<int, int>>> g;
vector<int> dist;
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  vector<tuple<int, int, int>> edges;
  vector<int> parent(n + 1, -1);
  dist.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    edges.push_back({u, v, w});
  }
  for (int i = 1; i <= n - 1; i++) {
    bool relaxed = false;
    for (auto [u, v, w] : edges) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        relaxed = true;
      }
    }
    if (!relaxed) {
      break;
    }
  }
  for (auto [u, v, w] : edges) {
    if (dist[v] > dist[u] + w) {
      yes;
      int x = v;
      for (int i = 0; i < n; i++) {
        x = parent[x];
      }
      vector<int> path;
      int cur = x;
      do {
        path.push_back(cur);
        cur = parent[cur];
      } while (cur != x);

      path.push_back(x);

      reverse(all(path));
      for (auto node : path)
        cout << node << " ";
      cout << endl;
      return;
    }
  }
  no;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}