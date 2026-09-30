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
int n, m, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dist;
vector<pair<int, int>> ks;
vector<tuple<int, int, int>> edges;
void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});
  dist[src][src] = 0;
  while (!pq.empty()) {
    auto [nddist, nd] = pq.top();
    pq.pop();
    for (auto [child, childcost] : g[nd]) {
      if (nddist + childcost < dist[src][child]) {
        dist[src][child] = nddist + childcost;
        pq.push({dist[src][child], child});
      }
    }
  }
}
void marwan() {
  cin >> n >> m >> k;
  g.assign(n + 1, vector<pair<int, int>>());
  dist.assign(n + 1, vector<int>(n + 1, INT_MAX));
  ks.assign(k, {0, 0});
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  for (int i = 0; i < k; i++)
    cin >> ks[i].first >> ks[i].second;
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
  }
  //   for (int i = 1; i <= n; i++) {
  //     cout << i << endl;
  //     for (int j = 1; j <= n; j++) {
  //       cout << dist[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  int ans = INT_MAX;
  for (auto [a, b, c] : edges) {
    int tans = 0;
    for (auto [x, y] : ks) {
      tans +=
          min({dist[x][y], dist[x][a] + dist[b][y], dist[x][b] + dist[a][y]});
    }
    ans = min(ans, tans);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}