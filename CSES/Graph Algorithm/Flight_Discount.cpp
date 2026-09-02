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
int n, m;
vector<vector<pair<int, int>>> g;
multiset<pair<int, int>> ms;
vector<int> parent;
vector<vector<int>> dist;
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  dist.assign(n + 1, vector<int>(2, INT_MAX));
  parent.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].push_back({y, z});
    // g[y].push_back({x, z});
  }
  // dist[i][0] -> distance without doing operations
  // dist[i][1] -> distance with doing operation
  dist[1][0] = dist[1][1] = 0;
  ms.insert({0, 1});
  while (!ms.empty()) {
    auto [d, u] = *ms.begin();
    ms.erase(ms.begin());
    if (d > dist[u][0])
      continue;
    for (auto [v, cost] : g[u]) {
      if (dist[u][0] + cost < dist[v][0]) {
        dist[v][0] = dist[u][0] + cost;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << dist[i].first << " " << dist[i].second << endl;
  cout << dist[n].first - (dist[n].second / 2) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}